<?php

/**
 * Class ModelDependent
 */
trait ModelDependent {
  /**
   * @var string $modelSysId
   *   The model sys id.
   */
  protected $modelSysId;
  /**
   * @access protected
   * @var string $modelName
   *   The model's name.
   */
  protected $modelName;
  /**
   * @access protected
   * @var string $modelClass
   *   The builder's model class.
   */
  protected $modelClass;
  /**
   * @access protected
   * @var ModelBase $model
   *   The data model object.
   */
  protected $model;

  /**
   * @return string
   */
  public function getModelSysId() {
    return $this->modelSysId;
  }

  /**
   * @param string $modelSysId
   */
  public function setModelSysId($modelSysId) {
    $this->modelSysId = $modelSysId;
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
   * Returns the Model class.
   *
   * @return string
   */
  public function getModelClass() {
    return $this->modelClass;
  }

  /**
   * Sets the Model class.
   *
   * @param string $modelClass
   */
  protected function setModelClass($modelClass) {
    $this->modelClass = $modelClass;
  }

  /**
   * @return ModelBase
   */
  public function getModel() {
    return $this->model;
  }

  /**
   * @param ModelBase $model
   */
  protected function setModel(ModelBase $model) {
    $this->model = $model;
  }

  /**
   * Returns an instance of a model.
   *
   * @param string $sysId
   * @param array  $args
   *
   * @return ModelBase
   */
  protected function modelGetInstance($sysId, array $args = array()) {
    return model($sysId, $args);
  }
}