<?php

/**
 * Class PhaseDependent
 */
trait PhaseDependent {
  /**
   * @var integer $phase
   *   The building phase :
   *   - PHZ__INIT : Initializing the builder.
   *   - PHZ__PREP : Preparing the builder.
   *   - PHZ__BUILD : Building.
   *   - PHZ__REBUILD : Rebuilding.
   *   - PHZ__VED : Validating the build/rebuild.
   *   - PHZ__DELIVER : Delivering.
   */
  protected $phase;

  /**
   * Returns the builds current phase.
   *
   * @return int
   */
  public function getPhase() {
    return $this->phase;
  }

  /**
   * Sets the builder current phase.
   *
   * @param int $phase
   *   The phase to set.
   */
  protected function setPhase($phase) {
    $this->phase = $phase;
  }

  /**
   * Sets the object phase to PHZ__INIT.
   */
  protected function initPhz(){
    $this->phase = PHZ__INIT;
  }

  /**
   * Sets the object phase to PHZ__PREP.
   */
  protected function prepPhz(){
    $this->phase = PHZ__PREP;
  }

  /**
   * Sets the object phase to PHZ__BUILD.
   */
  protected function buildPhz(){
    $this->phase = PHZ__BUILD;
  }

  /**
   * Sets the object phase to PHZ__REBUILD.
   */
  protected function rebuildPhz(){
    $this->phase = PHZ__REBUILD;
  }

  /**
   * Sets the object phase to PHZ__DELIVER.
   */
  protected function deliverPhz(){
    $this->phase = PHZ__DELIVER;
  }
}