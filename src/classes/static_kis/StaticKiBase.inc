<?php

trait_require_once('oop_common');
trait_require_once('ki_properties_dependent');

/**
 * Class StaticKiBase
 */
class StaticKiBase {

  use OopCommon,
    KiPropertiesDependent {
    OopCommon::setUp as oopSetUp;
  }

  /**
   * @access protected
   * @var string[] $staticDependencies
   *   The dependencies names.
   */
  protected $staticDependencies = array();

  /**
   * StaticKiBase constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $this->setUp($args);
  }

  /**
   * Set up method.
   *
   * @param array $args
   *   The set up args.
   */
  public function setUp(array $args = array()) {
    $this->oopSetUp($args);
  }

  /**
   * @return string[]
   */
  public function getStaticDependencies() {
    return $this->staticDependencies;
  }

  /**
   * @param string[] $staticDependencies
   */
  protected function setStaticDependencies($staticDependencies) {
    $this->staticDependencies = $staticDependencies;
  }

  /**
   * @param $name
   * @return $this
   */
  public function name($name) {
    $this->setName($name);

    return $this;
  }

  /**
   * @param $type
   * @return $this
   */
  public function type($type) {
    $this->setDataType($type);

    return $this;
  }

  /**
   * @param bool $required
   * @return $this
   */
  public function required($required = TRUE) {
    $this->required = $required;

    return $this;
  }

  /**
   * @param $default
   * @return $this
   */
  public function default_value($default) {
    $this->setDefault($default);

    return $this;
  }

  /**
   * @param $default
   * @return $this
   */
  public function default_fallback($default) {
    $this->defaultFallbacks[] = $default;

    return $this;
  }

  /**
   * @param $value
   * @return $this
   */
  public function allowed_value($value) {
    $this->allowedValues[] = $value;

    return $this;
  }

  /**
   * @param mixed       $condition
   * @param null|string $type
   * @param bool        $strict
   * @param bool        $negate
   *
   * @return $this
   */
  public function unset_condition($condition, $type = 'value', $strict = FALSE, $negate = FALSE) {
    $this->unsetConditions[] = array(
      'condition' => $condition,
      'type'      => $type,
      'strict'    => $strict,
      'negate'    => $negate
    );

    return $this;
  }

  /**
   * @param $id
   * @return $this
   */
  public function builder_sys_id($id) {
    $this->setBuilderSysId($id);

    return $this;
  }

  /**
   * @param $id
   * @return $this
   */
  public function model_sys_id($id) {
    $this->setModelSystemId($id);

    return $this;
  }

  /**
   * @param $id
   * @return $this
   */
  public function ki_sys_id($id) {
    $this->setKiSystemId($id);

    return $this;
  }

  /**
   * @param $weight
   * @return $this
   */
  public function weight($weight) {
    $this->setWeight($weight);

    return $this;
  }

  /**
   * @param      $dependency
   * @param bool $regexp
   *
   * @return $this
   */
  public function dependency($dependency, $regexp = FALSE) {
    $this->staticDependencies[] = $dependency;

    return $this;
  }
}