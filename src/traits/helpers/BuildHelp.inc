<?php

/**
 * Class BuildHelp
 */
trait BuildHelp {
  /**
   * __call magic method.
   *
   * @param $name
   * @param $arguments
   */
  public function __call($name, $arguments) {
    if (preg_match('/^buildKi\w+/', $name)) {
      if (method_exists($this, $name)) {
        $this->$name($arguments);
      }
    }
  }
}