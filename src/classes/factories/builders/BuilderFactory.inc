<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';


/**
 * Class ModelFactory
 */
class BuilderFactory extends FactoryBase {
  /**
   * @var string $builderSysId
   *   The builder's system ID.
   */
  protected $builderSysId;
  /**
   * @access protected
   * @var array $builderInfo
   *   The builder info.
   */
  protected $builderInfo = array();

  /**
   * ModelFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'name' => 'builder'
    ), $args);
    parent::__construct($args);
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
  public function setBuilderSysId($builderSysId) {
    $this->builderSysId = $builderSysId;
  }

  /**
   * @return array
   */
  public function getBuilderInfo() {
    return $this->builderInfo;
  }

  /**
   * @param array $builderInfo
   */
  public function setBuilderInfo($builderInfo) {
    $this->builderInfo = $builderInfo;
  }

  /**
   * @param $sysId
   *
   * @return $this
   */
  public function builder_sys_id($sysId) {
    $this->setBuilderSysId($sysId);
    $kiInfo = generator_builder_get_info($this->builderSysId);
    $this->setBuilderInfo($kiInfo);
    if (!empty($this->builderInfo['class alter'])) {
      $classAlter = $this->builderInfo['class alter'];
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
          $this->modelClass = $classAlter['ki']['class'];
          $this->patchModelClass();
        }
      }
    }
    $this->parsing_arg('builder_sys_id', str2camelcase($sysId));
    $this->instance_arg('builder_sys_id', $sysId);

    return $this;
  }
}