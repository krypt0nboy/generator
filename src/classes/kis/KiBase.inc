<?php

/**
 * Class KiBase
 */
class KiBase {

  use OopCommon,
    HelperDependent,
    TemplaterDependent,
    ModelDependent,
    StructureDependent,
    BuildDependent,
    BuilderDependent {
    OopCommon::setUp as oopSetUp;
    HelperDependent::getHelper as hlpr;
  }

  /**
   * @access protected
   * @var string $name
   *   The key's name.
   */
  protected $name;
  /**
   * @access protected
   * @var string $type
   *   The key's value type.
   */
  protected $type;
  /**
   * @access protected
   * @var mixed $defaultValue
   *   The key's default value.
   */
  protected $defaultValue;
  /**
   * @access protected
   * @var string $modelName
   *   The model's name.
   */
  protected $modelName;
  /**
   * @access protected
   * @var array $unsetConditions
   *   The unset conditions.
   */
  protected $unsetConditions = array();
  /**
   * @access protected
   * @var array $selfStaticParams
   *   The Ki self static params, retrieved from a model key.
   */
  protected $selfStaticParams = array();

  /**
   * @var integer $phase
   *   The building phase :
   *   - PHZ__INIT : Initializing the builder.
   *   - PHZ__PREP : Preparing the builder.
   *   - PHZ__BUILD : Building.
   *   - PHZ__REBUILD : Rebuilding.
   *   - PHZ__VED : Validating the build/rebuild.
   *   - PHZ__DELIVER : Delivering.
   */
  protected $phase;
  /**
   * @const PHZ__INIT
   */
  const PHZ__INIT = 0x001;
  /**
   * @const PHZ__PREP
   */
  const PHZ__PREP = 0x002;
  /**
   * @const PHZ__BUILD
   */
  const PHZ__BUILD = 0x003;
  /**
   * @const PHZ__REBUILD
   */
  const PHZ__REBUILD = 0x004;
  /**
   * @const PHZ__VED
   */
  const PHZ__VED = 0x005;
  /**
   * @const PHZ__DELIVER
   */
  const PHZ__DELIVER = 0x006;

  /**
   * BuilderBase constructor.
   *
   * @param array $args
   *   The properties to set.
   *
   * @throws EntityToolboxException
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
    $this->setPhase(self::PHZ__INIT);
    $this->oopSetUp($args);
    $this->autoSet();
    $this->prepare();
  }

  /**
   * Init phase where construct args are set.
   *
   * @param array $args
   */
  protected function constructSet($args) {
    $this->setPhase(self::PHZ__INIT);
    $this->setConstructArgs($args);
    $this->bulkSet($args);
  }

  /**
   * Auto sets properties.
   */
  protected function autoSet() {
    $this->autoSetHelper();
  }

  /**
   * Auto sets the main helper.
   */
  protected function autoSetHelper() {
    $helper = $this->helperGetInstance('Builder');
    $this->setHelper($helper);
  }

  /**
   * Prepares the builder structure and components.
   */
  protected function prepare() {
    $this->setPhase(self::PHZ__PREP);
    $this->initTplVars();
  }

  /**
   * @return string
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param string $name
   */
  public function setName($name) {
    $this->name = $name;
  }

  /**
   * @return string
   */
  public function getType() {
    return $this->type;
  }

  /**
   * @param string $type
   */
  public function setType($type) {
    $this->type = $type;
  }

  /**
   * @return mixed
   */
  public function getDefaultValue() {
    return $this->defaultValue;
  }

  /**
   * @param mixed $defaultValue
   */
  public function setDefaultValue($defaultValue) {
    $this->defaultValue = $defaultValue;
  }

  /**
   * @return string
   */
  public function getModelName() {
    return $this->modelName;
  }

  /**
   * @param string $modelName
   */
  public function setModelName($modelName) {
    $this->modelName = $modelName;
  }

  /**
   * @return array
   */
  public function getUnsetConditions() {
    return $this->unsetConditions;
  }

  /**
   * @param array $unset
   */
  public function setUnsetConditions(array $unset = array()) {
    $this->unsetConditions = $unset;
  }

  /**
   * Returns the builds current phase.
   *
   * @return int
   */
  public function getPhase() {
    return $this->phase;
  }

  /**
   * Sets the builder current phase.
   *
   * @param int $phase
   *   The phase to set.
   */
  protected function setPhase($phase) {
    $this->phase = $phase;
  }
}