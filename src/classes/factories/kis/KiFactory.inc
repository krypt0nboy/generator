<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';

/**
 * Class KiFactory
 */
class KiFactory extends FactoryBase {
  /**
   * @access protected
   * @var string $kiSysId
   *   The Ki sys id.
   */
  protected $kiSysId;
  /**
   * @access protected
   * @var array $kiInfo
   *   The Ki info.
   */
  protected $kiInfo = array();

  /**
   * GeneratorFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'class_sys_id' => 'ki'
    ), $args);
    parent::__construct($args);
  }

  /**
   * @return string
   */
  public function getKiSysId() {
    return $this->kiSysId;
  }

  /**
   * @param string $kiSysId
   */
  public function setKiSysId($kiSysId) {
    $this->kiSysId = $kiSysId;
  }

  /**
   * @return array
   */
  public function getKiInfo() {
    return $this->kiInfo;
  }

  /**
   * @param array $kiInfo
   */
  public function setKiInfo($kiInfo) {
    $this->kiInfo = $kiInfo;
  }

  /**
   * @param string $sysId
   *   The Ki sys ID.
   *
   * @return $this
   */
  public function ki_sys_id($sysId) {
    $this->setKiSysId($sysId);
    $kiInfo = generator_ki_get_info($this->kiSysId);
    $this->setKiInfo($kiInfo);
    if (!empty($this->kiInfo['class alter'])) {
      $classAlter = $this->kiInfo['class alter'];
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
    $this->parsing_arg('ki_sys_id', str2camelcase($sysId));
    $this->instance_arg('ki_sys_id', $sysId);

    return $this;
  }
}