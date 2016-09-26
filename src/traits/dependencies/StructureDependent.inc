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
  protected function setStructure(array $structure = array()) {
    $this->structure = $structure;
  }
}