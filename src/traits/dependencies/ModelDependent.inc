<?php

/**
 * Class ModelDependent
 */
trait ModelDependent {
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
   * @param string $name
   * @param array  $args
   *
   * @return ModelBase
   */
  protected function modelGetInstance($name, array $args = array()) {
    $factory = new ModelFactory();

    return $factory->getInstance($args);
  }
}