<?php

/**
 * Class ModelBase
 */
class ModelBase {

  use
    OopCommon,
    TemplaterDependent {
    OopCommon::setUp as oopSetUp;
  }

  /**
   * @access protected
   * @var array $structure
   *   The structure of the build.
   */
  protected $structure = array();

  /**
   * ModelBase_ constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $this->setUp($args);
  }

  /**
   * Set up method.
   *
   * @param array $args
   */
  public function setUp(array $args = array()) {
    $this->oopSetUp($args);
  }

  /**
   * Gets the data structure.
   *
   * @param string $key
   *   A key.
   *
   * @return array
   */
  public function getStructure($key = NULL) {
    return isset($key) ? $this->structure[$key] : $this->structure;
  }

  /**
   * @param array $structure
   */
  protected function setStructure(array $structure = array()) {
    $this->structure = $structure;
  }
}