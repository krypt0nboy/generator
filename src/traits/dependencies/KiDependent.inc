<?php

/**
 * Class KiDependent
 */
trait KiDependent {
  /**
   * @var KiBase $ki
   *   The object's Ki.
   */
  protected $ki;

  /**
   * @return KiBase
   */
  public function getKi() {
    return $this->ki;
  }

  /**
   * @param KiBase $ki
   */
  public function setKi(KiBase $ki) {
    $this->ki = $ki;
  }
}