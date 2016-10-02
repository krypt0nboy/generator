<?php

/**
 * Class StructureDependent
 */
trait StructureDependent {
  /**
   * @access protected
   * @var KiBase[] $structure
   *   The structure of the build.
   *   An array of kis.
   */
  protected $structure = array();

  /**
   * Gets the data structure.
   *
   * @param string $key
   *   A key.
   *
   * @return KiBase[]|KiBase
   */
  public function getStructure($key = NULL) {
    return isset($key) ? $this->structure[$key] : $this->structure;
  }

  /**
   * @param KiBase[] $structure
   */
  public function setStructure(array $structure = array()) {
    foreach ($structure as $ki) {
      $this->setStructureKi($ki);
    }
  }

  /**
   * Sets a static ki in structure.
   *
   * @param \KiBase $ki
   */
  protected function setStructureKi(KiBase $ki) {
    $this->structure[$ki->getName()] = $ki;
  }

  /**
   * Generates a structure from a Model.
   *
   * @return KiBase[]
   */
  protected function genFromModel() {
    $structure = array();
    /** @var ModelBase $model */
    $model = $this->getModel();
    /** @var StaticKiBase $staticKi */
    foreach ($model->getStaticStructure() as $staticKi) {
      $factArgs = array(
        'instance_args' => array('static_ki' => $staticKi)
      );
      if ($staticKi->getModelSystemId() !== NULL) {
        $factArgs['instance_args']['model_system_id'] = $staticKi->getModelSystemId();
      }
      if ($staticKi->__isset('ki_system_id')) {
        $ki = ki($staticKi->getKiSystemId(), $factArgs);
      }
      else {
        $kis_info = generator_ki_get_info();
        if (in_array($staticKi->getDataType(), array_keys($kis_info))) {
          $ki = ki($staticKi->getDataType(), $factArgs);
        }
        else {
          $type = ($staticKi->getDataType() == 'array') || (preg_match(RGX__PHPDOC_ARRAY, $staticKi->getDataType())) ? 'array' : 'non_array';
          $ki   = ki($type, $factArgs);
        }
      }
      $structure[$ki->getName()] = $ki;
    }

    return $structure;
  }

  /**
   *  Generates a dynamic structure.
   *
   * @return KiBase[]
   */
  protected function genDynamic() {

  }

  /**
   * Validates a structure.
   *
   * @param array $structure
   *   The structure to ved.
   *
   * @return KiBase[]
   */
  public function vedStructure($structure) {
    /** @var KiBase $ki2Ved */
    foreach ($structure as $ki2Ved) {

    }

    return $structure;
  }
}