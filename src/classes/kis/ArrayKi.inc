<?php

require_once 'KiBase.inc';

/**
 * Class MultiValueKi
 */
class ArrayKi extends KiBase {
  /** {{@inheritdoc}} */
  protected function prepare() {
    parent::prepare();
    $this->prepareStructure();
  }

  /** {{@inheritdoc}} */
  protected function build() {
    foreach ($this->getStructure() as $ki) {
      $ki->_build();
    }
  }
}