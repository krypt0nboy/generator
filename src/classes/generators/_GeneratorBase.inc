<?php

trait_require_once('oop_common');
trait_require_once('templater_dependent');
trait_require_once('helper_dependent');
trait_require_once('phase_dependent');
trait_require_once('model_dependent');
trait_require_once('structure_dependent');
trait_require_once('structure_help');
trait_require_once('build_dependent');

/**
 * Class GeneratorBase
 */
class _GeneratorBase {

  use
    OopCommon,
    TemplaterDependent,
    HelperDependent,
    PhaseDependent,
    ModelDependent,
    StructureDependent,
    StructureHelp,
    BuildDependent {
    OopCommon::setUp as oopSetUp;
    HelperDependent::getHelper as hlp;
  }

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
   * Auto sets properties.
   */
  protected function autoSet() {
    $this->autoSetTemplater();
    $this->instanciateComponents();
  }

  /**
   * Auto sets the main helper.
   */
  protected function autoSetHelper() {
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
   * Instanciates required components.
   */
  protected function instanciateComponents() {
    $this->instanciateModel();
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
    if ($this->__isset('model_sys_id')) {
      $instance = model($this->modelSysId);
      if ($autoSet) {
        $this->setModel($instance);
      }

      return $instance;
    }
  }

  /*** INIT END ***/

  /*** SETTERS AND GETTERS ***/
  /*** SETTERS AND GETTERS END ***/

  /*** PREPARE ***/

  protected function prepare() {
    $this->prepPhz();
    $this->prepareStructure();
  }

  /**
   * @return KiBase[]
   */
  protected function prepareStructure() {
    $method    = $this->structGenMethodGuess();
    $structure = $this->$method();
    $ved       = $this->vedStructure($structure);
    $this->setStructure($ved);

    return $ved;
  }

  /*** PREPARE END ***/

  /*** GENERATE ***/

  /**
   * Launch generate and return the generated build.
   *
   * @return mixed
   */
  public function _generate() {
    $this->preGenerate();
    $this->validate();
    $this->generate();
    $this->postGenerate();

    return $this->deliver();
  }

  /**
   * Called before the build is actually generated.
   */
  public function preGenerate() {
  }

  /**
   * Default generate method.
   */
  public function generate() {
    foreach ($this->getStructure() as $ki) {
      $ki->_build();
    }
  }

  /**
   * Post generate method.
   */
  protected function postGenerate() {
  }

  /*** GENERATE END ***/

  /*** VALIDATE ***/

  /**
   * Validates the generated build.
   *
   * @return bool
   */
  public function validate() {
  }

  /*** VALIDATE END ***/

  /*** DELIVER ***/

  /**
   * Returns the generated build.
   *
   * @return mixed
   */
  public function deliver() {
  }

  /**
   * Fix a build that failed to deliver.
   *
   * @return bool
   */
  public function deliverFailFix() {
  }

  /*** DELIVER END ***/


}