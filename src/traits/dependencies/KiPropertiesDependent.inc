<?php

/**
 * Class KiPropertiesDependent
 */
trait KiPropertiesDependent {
  /**
   * @access protected
   * @var string $kiSystemId
   *   The ki system identifier.
   */
  protected $kiSystemId;
  /**
   * @access protected
   * @var string $name
   *   The ki's name.
   */
  protected $name;
  /**
   * @access protected
   * @var bool $required
   *   Whether this Ki is required.
   */
  protected $required = TRUE;
  /**
   * @access protected
   * @var string $dataType
   *   The data type.
   */
  protected $dataType;
  /**
   * @access protected
   * @var mixed $default
   *   The Ki's default value.
   */
  protected $default;
  /**
   * @access protected
   * @var array $defaultFallback
   *   The Ki's fallback default values in case the prime one failed to process.
   */
  protected $defaultFallbacks = array();
  /**
   * @access protected
   * @var array $allowedValues
   *   The allowed values for this Ki.
   */
  protected $allowedValues = array();
  /**
   * @access protected
   * @var array $unsetConditions
   *   The unset conditions.
   */
  protected $unsetConditions = array();
  /**
   * @access protected
   * @var string $builderSysId
   *   The Ki builder system identifier.
   */
  protected $builderSysId;
  /**
   * @access protected
   * @var string $modelSystemId
   *   The Ki model's system identifier.
   */
  protected $modelSystemId;
  /**
   * @access protected
   * @var int $weight
   *   The Ki's weight in relation to others.
   */
  protected $weight = 0;
  /**
   * @access protected
   * @var KiBase[] $dependencies
   *   An array of Kis on which this Ki depends.
   */
  protected $dependencies = array();

  /**
   * @return string
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param string $name
   */
  protected function setName($name) {
    $this->name = $name;
  }

  /**
   * @return boolean
   */
  public function isRequired() {
    return $this->required;
  }

  /**
   * @param boolean $required
   */
  protected function setRequired($required) {
    $this->required = $required;
  }

  /**
   * @return string
   */
  public function getDataType() {
    return $this->dataType;
  }

  /**
   * @param string $dataType
   */
  protected function setDataType($dataType) {
    $this->dataType = $dataType;
  }

  /**
   * @return mixed
   */
  public function getDefault() {
    return $this->default;
  }

  /**
   * @param mixed $default
   */
  protected function setDefault($default) {
    $this->default = $default;
  }

  /**
   * @return array
   */
  public function getDefaultFallbacks() {
    return $this->defaultFallbacks;
  }

  /**
   * @param array $defaultFallbacks
   */
  public function setDefaultFallbacks($defaultFallbacks) {
    $this->defaultFallbacks = $defaultFallbacks;
  }

  /**
   * @return array
   */
  public function getAllowedValues() {
    return $this->allowedValues;
  }

  /**
   * @param array $allowedValues
   */
  protected function setAllowedValues($allowedValues) {
    $this->allowedValues = $allowedValues;
  }

  /**
   * @return array
   */
  public function getUnsetConditions() {
    return $this->unsetConditions;
  }

  /**
   * @param array $unsetConditions
   */
  protected function setUnsetConditions($unsetConditions) {
    $this->unsetConditions = $unsetConditions;
  }

  /**
   * @return string
   */
  public function getKiSystemId() {
    return $this->kiSystemId;
  }

  /**
   * @param string $kiSystemId
   */
  protected function setKiSystemId($kiSystemId) {
    $this->kiSystemId = $kiSystemId;
  }

  /**
   * @return string
   */
  public function getBuilderSysId() {
    return $this->builderSysId;
  }

  /**
   * @param string $builderSysId
   */
  protected function setBuilderSysId($builderSysId) {
    $this->builderSysId = $builderSysId;
  }

  /**
   * @return string
   */
  public function getModelSystemId() {
    return $this->modelSystemId;
  }

  /**
   * @param string $modelSystemId
   */
  protected function setModelSystemId($modelSystemId) {
    $this->modelSystemId = $modelSystemId;
  }

  /**
   * @return int
   */
  public function getWeight() {
    return $this->weight;
  }

  /**
   * @param int $weight
   */
  protected function setWeight($weight) {
    $this->weight = $weight;
  }

  /**
   * @return KiBase[]
   */
  public function getDependencies() {
    return $this->dependencies;
  }

  /**
   * @param KiBase[] $dependencies
   */
  protected function setDependencies($dependencies) {
    $this->dependencies = $dependencies;
  }

  /**
   * @param KiBase|StaticKiBase $dependency
   */
  protected function setDependency($dependency) {
    $this->dependencies[$dependency->getName()] = $dependency;
  }
}