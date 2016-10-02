<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';
require_once GENERATOR_PATH . '/src/classes/generators/_GeneratorBase.inc';

/**
 * Class GeneratorFactory
 */
class GeneratorFactory extends FactoryBase {
  /**
   * @access protected
   * @var string $generatorSysId
   *   The generator's system ID.
   */
  protected $generatorSysId;
  /**
   * @access protected
   * @var array $generatorInfo
   *   The generator info.
   */
  protected $generatorInfo = array();

  /**
   * GeneratorFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'class_sys_id' => 'generator'
    ), $args);
    parent::__construct($args);
  }

  /**
   * @return string
   */
  public function getGeneratorSysId() {
    return $this->generatorSysId;
  }

  /**
   * @param string $generatorSysId
   */
  public function setGeneratorSysId($generatorSysId) {
    $this->generatorSysId = $generatorSysId;
  }

  /**
   * @return array
   */
  public function getGeneratorInfo() {
    return $this->generatorInfo;
  }

  /**
   * @param array $generatorInfo
   */
  public function setGeneratorInfo($generatorInfo) {
    $this->generatorInfo = $generatorInfo;
  }

  /**
   * @param $sysId
   * @return $this
   */
  public function generator_sys_id($sysId) {
    $this->setGeneratorSysId($sysId);
    $generatorInfo = generator_generator_get_info($this->generatorSysId);
    $this->setGeneratorInfo($generatorInfo);
    if (!empty($this->generatorInfo['class alter'])) {
      $classAlter = $this->generatorInfo['class alter'];
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
    $this->parsing_arg('generator_sys_id', str2camelcase($sysId));
    $this->instance_arg('generator_sys_id', $sysId);

    return $this;
  }
}