<?php

require_once OOP_PATH . '/src/traits/OopCommon.inc';

/**
 * Class VariableBase
 */
class VariableBase {

  use OopCommon {
    OopCommon::setUp as oopSetUp;
  }
  /**
   * @access protected
   * @var string $phpType
   *   The php variable type.
   */
  protected $phpType = '';

  /**
   * VariableBase constructor.
   *
   * @param array $args
   *   The construct args.
   */
  public function __construct(array $args = array()) {
    $this->setUp($args);
  }

  /**
   * Set up method.
   *
   * @param array $args
   *   The set up args.
   */
  public function setUp(array $args = array()) {
    $this->oopSetUp($args);
  }

  /**
   * @return string
   */
  public function getPhpType() {
    return $this->phpType;
  }

  /**
   * @param string $phpType
   */
  public function setPhpType($phpType) {
    $this->phpType = $phpType;
  }
}