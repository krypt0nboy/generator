<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';
require_once GENERATOR_PATH . '/src/classes/generators/_GeneratorBase.inc';

/**
 * Class GeneratorFactory
 */
class GeneratorFactory extends FactoryBase {
  /**
   * GeneratorFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'name' => 'generator'
    ), $args);
    parent::__construct($args);
  }

  /** {{@inheritdoc}} */
  protected function ensureClass() {
    $ensure = parent::ensureClass();
    if ($this->instanceClass == 'Generator') {
      $this->instanceClass = $this->baseClass;
    }

    return $ensure;
  }
}