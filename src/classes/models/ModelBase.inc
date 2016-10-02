<?php

trait_require_once('oop_common');
trait_require_once('templater_dependent');
trait_require_once('static_structure_dependent');

/**
 * Class ModelBase
 */
class ModelBase {

  use
    OopCommon,
    TemplaterDependent,
    StaticStructureDependent {
    OopCommon::setUp as oopSetUp;
  }

  /**
   * ModelBase_ constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array('static_structure' => $this->defaultStatic()));
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
   * Returns the default StaticKis.
   *
   * @return StaticKiBase[]
   */
  public function defaultStatic() {
    return array();
  }

}