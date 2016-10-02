<?php

trait_require_once('oop_common');
trait_require_once('templater_dependent');
trait_require_once('ki_properties_dependent');
trait_require_once('ki_help');
trait_require_once('phase_dependent');
trait_require_once('model_dependent');
trait_require_once('structure_dependent');
trait_require_once('structure_help');
trait_require_once('build_dependent');
trait_require_once('builder_dependent');

/**
 * Class KiBase
 */
class KiBase {

  use
    OopCommon,
    TemplaterDependent,
    KiPropertiesDependent,
    KiHelp,
    ModelDependent,
    StructureDependent,
    BuildDependent,
    BuilderDependent,
    PhaseDependent,
    StructureHelp {
    OopCommon::setUp as oopSetUp;
    OopCommon::__call as oopCall;
    TemplaterDependent::initTplVars as templaterInitVars;
  }

  /**
   * @access protected
   * @var StaticKiBase $staticKi
   *   The Ki's static Ki from its model.
   */
  protected $staticKi;
  /**
   * @access protected
   * @var KiBase $parentKi
   *   The parent Ki.
   */
  protected $parentKi;

  /**
   * BuilderBase constructor.
   *
   * @param array $args
   *   The properties to set.
   */
  public function __construct(array $args = array()) {
    $this->setUp($args);
  }

  /**
   * __toString magic method.
   *
   * @return string
   */
  public function __toString() {
    return $this->name;
  }

  /**
   * __call magic method.
   *
   * @param $name
   * @param $arguments
   */
  public function __call($name, $arguments) {
    if (!method_exists($this, $name) && ($name != 'autoSetFrom')) {
      if (preg_match('/^autoSet\w+From$/', $name)) {
        $regexp = '/^autoSet(?P<property>.+)From$/';
        preg_match($regexp, $name, $matches);
        $property = $matches['property'];
        list($from) = $arguments;
        $this->autoSetFrom($property, $from);
      }
    }
  }

  /**
   * @return StaticKiBase
   */
  public function getStaticKi() {
    return $this->staticKi;
  }

  /**
   * @param StaticKiBase $staticKi
   */
  public function setStaticKi($staticKi) {
    $this->staticKi = $staticKi;
  }

  /**
   * @return KiBase
   */
  public function getParentKi() {
    return $this->parentKi;
  }

  /**
   * @param KiBase $parentKi
   */
  public function setParentKi(KiBase $parentKi) {
    $this->parentKi = $parentKi;
  }

  /**
   * Set up function.
   * Sets the object, and ensures he is ready to build.
   *
   * @param array $args
   *   The args to provide for the builder.
   */
  public function setUp($args = array()) {
    $this->initPhz();
    $this->oopSetUp($args);
    $this->autoSet();
    $this->prepare();
  }

  /**
   * Auto set methods call.
   */
  protected function autoSet() {
    $this->autoSetFromStaticKi();
    $this->autoSetTemplater();
    $this->instanciateComponents();
  }

  /**
   * Auto set properties from the static Ki.
   */
  protected function autoSetFromStaticKi() {
    /** @var StaticKiBase $staticKi */
    $staticKi = $this->getStaticKi();
    if (isset($staticKi)) {
      $this->autoSetNameFrom($staticKi);
      $this->autoSetRequiredFrom($staticKi);
      $this->autoSetDataTypeFrom($staticKi);
      $this->autoSetDefaultFrom($staticKi);
      $this->autoSetDefaultFallbacksFrom($staticKi);
      $this->autoSetAllowedValuesFrom($staticKi);
      $this->autoSetUnsetConditionsFrom($staticKi);
      $this->autoSetBuilderSysIdFrom($staticKi);
      $this->autoSetModelSysIdFrom($staticKi);
      $this->autoSetWeightFrom($staticKi);
      $this->autoSetDependenciesFrom($staticKi);
    }
    if (isset($this->modelSysId)) {
      $this->modelSystemId = $this->modelSysId;
    }
  }

  /**
   * Auto sets a property from another object.
   *
   * @param string $property
   * @param object $from
   */
  protected function autoSetFrom($property, $from) {
    if (!$this->__isset($property)) {
      $this->setFrom($property, $from);
    }
  }

  /**
   * Sets a property from another object.
   *
   * @param string $property
   * @param object $from
   */
  protected function setFrom($property, $from) {
    $lProperty = camelcase2lowercase($property);
    $value     = $from->__get($lProperty);
    $setMethod = 'set' . $property;
    if (method_exists($this, $setMethod)) {
      $this->$setMethod($value);
    }
  }

  /**
   * Auto sets the Templater.
   */
  protected function autoSetTemplater() {
    $templater = $this->templaterGetInstance();
    $this->setTemplater($templater);
    $this->initTplVars();
  }

  /**
   * Initialize the templater variables.
   *
   * @param array $vars
   *   The templating vars.
   */
  public function initTplVars(array $vars = array()) {
    $this->templaterInitVars($vars);
  }

  /*** PREPARE ***/

  /**
   * Prepares the builder structure and components.
   */
  protected function prepare() {
    $this->prepPhz();
  }

  /**
   * Instanciates required components.
   */
  protected function instanciateComponents() {
    $this->instanciateModel();
    $this->instanciateBuilder();
  }

  /**
   * Instanciates the model from the model's name.
   *
   * @param array $args
   *   The args to pass when instanciating the model.
   * @param bool  $autoSet
   *   Whether to set as model the instanciated model.
   *
   * @return ModelBase
   */
  protected function instanciateModel(array $args = array(), $autoSet = TRUE) {
    if ($this->__isset('model_system_id')) {
      $instance = model($this->modelSystemId);
      if ($autoSet) {
        $this->setModel($instance);
      }

      return $instance;
    }
  }

  /**
   * Instanciates the builder from the builder's name.
   *
   * @param array $args
   *   The args to pass when instanciating the builder.
   * @param bool  $autoSet
   *   Whether to set as model the instanciated builder.
   *
   * @return BuilderBase
   */
  protected function instanciateBuilder(array $args = array(), $autoSet = TRUE) {
    if ($this->__isset('builder_sys_id')) {
      $instance = $this->builderGetInstance($this->builderSysId, $args);
      if ($autoSet) {
        $this->setBuilder($instance);
      }

      return $instance;
    }
  }

  /**
   * @return KiBase[]
   */
  protected function prepareStructure() {
    $method    = $this->structGenMethodGuess();
    $structure = $this->$method();
    if (!empty($structure)) {
      $ved = $this->vedStructure($structure);
      $this->setStructure($ved);

      return $ved;
    }
  }

  /*** PREPARE END ***/

  /*** BUILD ***/

  /**
   * Main build method.
   */
  public function _build() {
    $this->preBuild();
    $this->build();
    $this->postBuild();
    $this->buildValidate();

    return $this->deliver();
  }

  /**
   * Rebuild method.
   *
   * @param bool $preBuild
   *   Whether to call preBuild or not.
   * @param bool $postBuild
   *   Whether to call postBuild or not.
   * @param bool $validate
   *   Whether to call validate or not.
   */
  protected function rebuild($preBuild = FALSE, $postBuild = FALSE, $validate = TRUE) {
    if ($preBuild) {
      $this->preBuild();
    }
    $this->build();
    if ($postBuild) {
      $this->postBuild();
    }
    if ($validate) {
      $this->buildValidate();
    }
  }

  /**
   * Called before the ki is built.
   */
  protected function preBuild() {
  }

  /**
   * Build method.
   * Calls the builder.
   *
   * @return mixed
   */
  protected function build() {
    $build = $this->getBuilder()->build();
    $this->builtPP();

    return $build;
  }

  /**
   * Post build method.
   */
  protected function postBuild() {
  }

  /**
   * Returns the built content.
   *
   * @return mixed
   */
  protected function deliver() {
    if (!$this->isReady2Deliver()) {
      $fix = $this->deliverFailFix();
      $this->setReady2Deliver($fix);

      return $this->deliver();
    }
    else {
      return $this->buildAssemble();
    }
  }

  /**
   * Returns the assembled build.
   *
   * @return mixed
   */
  protected function buildAssemble() {
    return array($this->name => $this->build);
  }

  /*** BUILD END ***/

  /*** VALIDATE ***/

  /**
   * Validate method.
   *
   * @return bool
   */
  protected function buildValidate() {
  }

  /**
   * Fix method when failed to deliver.
   *
   * @return bool
   */
  protected function deliverFailFix() {
    if ($this->fixCount <= $this->deliverFixLimit) {
      $this->fixPP();

      return $this->deliverFailFixExec();
    }
    else {
      return TRUE;
    }
  }

  /**
   * Fix method when failed to deliver.
   *
   * @return bool
   */
  protected function deliverFailFixExec() {
    if ($this->isRebuildRequired()) {
      $this->rebuild();
    }
  }

  /*** VALIDATE END ***/
}