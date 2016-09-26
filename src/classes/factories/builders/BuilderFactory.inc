<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';
require_once GENERATOR_PATH . '/src/classes/builders/BuilderFactory.inc';


/**
 * Class ModelFactory
 */
class BuilderFactory extends FactoryBase {
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
}