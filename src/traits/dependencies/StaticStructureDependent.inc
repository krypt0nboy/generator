<?php

require_once GENERATOR_PATH . '/src/classes/static_kis/StaticKiBase.inc';

/**
 * Class StaticStructureDependent
 */
trait StaticStructureDependent {
  /**
   * @access protected
   * @var array $staticStructure
   *   The object static structure.
   */
  protected $staticStructure = array();

  /**
   * @return array
   */
  public function getStaticStructure() {
    return $this->staticStructure;
  }

  /**
   * @param StaticKiBase[] $structure
   */
  public function setStaticStructure(array $structure = array()) {
    foreach ($structure as $staticKi) {
      $this->setStaticStructureKi($staticKi);
    }
  }

  /**
   * Sets a static ki in structure.
   *
   * @param \StaticKiBase $ki
   */
  public function setStaticStructureKi(StaticKiBase $ki) {
    $this->staticStructure[$ki->getName()] = $ki;
  }
}