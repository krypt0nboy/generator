<?php

/**
 * Class BuildDependent
 */
trait BuildDependent {
  /**
   * @access protected
   * @var mixed $build
   *   The object's build.
   */
  protected $build;

  /**
   * @return mixed
   */
  public function getBuild() {
    return $this->build;
  }

  /**
   * @param mixed $build
   */
  public function setBuild($build) {
    $this->build = $build;
  }
}