<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';
require_once GENERATOR_PATH . '/src/classes/models/ModelBase.inc';

/**
 * Class ModelFactory
 */
class ModelFactory extends FactoryBase {
  /**
   * ModelFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'name' => 'model'
    ), $args);
    parent::__construct($args);
  }
}