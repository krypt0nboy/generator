<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';
require_once GENERATOR_PATH . '/src/classes/models/ModelBase.inc';

/**
 * Class ModelFactory
 */
class ModelFactory extends FactoryBase {
  /**
   * @var string $modelSysId
   *   The model's system ID.
   */
  protected $modelSysId;
  /**
   * @access protected
   * @var array $modelInfo
   *   The model info.
   */
  protected $modelInfo = array();

  /**
   * ModelFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'class_sys_id' => 'model'
    ), $args);
    parent::__construct($args);
  }

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
   * @return array
   */
  public function getModelInfo() {
    return $this->modelInfo;
  }

  /**
   * @param array $modelInfo
   */
  public function setModelInfo($modelInfo) {
    $this->modelInfo = $modelInfo;
  }

  /**
   * @param $modelSysId
   *
   * @return $this
   */
  public function model_sys_id($modelSysId) {
    $this->setModelSysId($modelSysId);
    $modelInfo = generator_model_get_info($this->modelSysId);
    $this->setModelInfo($modelInfo);
    if (!empty($this->modelInfo['class alter'])) {
      $classAlter = $this->modelInfo['class alter'];
      if (!empty($classAlter['module'])) {
        $this->moduleName = $classAlter['module'];
        $this->moduleInfo = module_get_info($this->moduleName);
        $this->modulePath = $this->moduleInfo['path'];
      }
      if (!empty($classAlter['dependency dir'])) {
        $this->dependencyDir = paths_join($this->dependencyDir, array($classAlter['dependency dir']));
      }
      if (!empty($classAlter['model'])) {
        if (!empty($classAlter['model']['class'])) {
          $this->modelClass = $classAlter['model']['class'];
          $this->patchModelClass();
        }
      }
    }
    $this->parsing_arg('model_sys_id', str2camelcase($modelSysId));
    $this->instance_arg('model_sys_id', $modelSysId);

    return $this;
  }
}