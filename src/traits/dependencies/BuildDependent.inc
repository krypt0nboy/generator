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
   * @access protected
   * @var mixed $tmpBuild
   *   The object's temporary build.
   */
  protected $tmpBuild;
  /**
   * @access protected
   * @var bool $built
   *   Whether the built is done.
   */
  protected $built;
  /**
   * @access protected
   * @var bool $rebuilt
   *   Whether it has been rebuilt.
   */
  protected $rebuilt;
  /**
   * @access protected
   * @var bool $buildVed
   *   Whether has been validated.
   */
  protected $buildVed;
  /**
   * @access protected
   * @var int $buildStatus
   *   The build status.
   */
  protected $buildStatus;
  /**
   * @access protected
   * @var int $builtCount
   *   The number of times the build was generated.
   */
  protected $builtCount = 0;
  /**
   * @access protected
   * @var int $fixCount
   *   The number of times the built was fixed.
   */
  protected $fixCount = 0;
  /**
   * @access protected
   * @var int $deliverFixLimit
   *   The maximum number of times to try to fix the build before it is delivered.
   */
  protected $deliverFixLimit = 1;
  /**
   * @access protected
   * @var bool $rebuildRequired
   *   Whether this build requires to be rebuilt.
   */
  protected $rebuildRequired;
  /**
   * @access protected
   * @var bool $ready2Deliver
   *   Whether the build is ready to be delivered.
   */
  protected $ready2Deliver = FALSE;

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

  /**
   * @return mixed
   */
  public function getTmpBuild() {
    return $this->tmpBuild;
  }

  /**
   * @param mixed $tmpBuild
   */
  public function setTmpBuild($tmpBuild) {
    $this->tmpBuild = $tmpBuild;
  }

  /**
   * @return boolean
   */
  public function isBuilt() {
    return $this->built;
  }

  /**
   * @param boolean $built
   */
  public function setBuilt($built) {
    $this->built = $built;
  }

  /**
   * @return boolean
   */
  public function isRebuilt() {
    return $this->rebuilt;
  }

  /**
   * @param boolean $rebuilt
   */
  public function setRebuilt($rebuilt) {
    $this->rebuilt = $rebuilt;
  }

  /**
   * @return boolean
   */
  public function isBuildVed() {
    return $this->buildVed;
  }

  /**
   * @param boolean $buildVed
   */
  public function setBuildVed($buildVed) {
    $this->buildVed = $buildVed;
  }

  /**
   * @return int
   */
  public function getBuildStatus() {
    return $this->buildStatus;
  }

  /**
   * @param int $buildStatus
   */
  public function setBuildStatus($buildStatus) {
    $this->buildStatus = $buildStatus;
  }

  /**
   * @return int
   */
  public function getBuiltCount() {
    return $this->builtCount;
  }

  /**
   * @param int $builtCount
   */
  public function setBuiltCount($builtCount) {
    $this->builtCount = $builtCount;
  }

  /**
   * @return int
   */
  public function getFixCount() {
    return $this->fixCount;
  }

  /**
   * @param int $fixCount
   */
  public function setFixCount($fixCount) {
    $this->fixCount = $fixCount;
  }

  /**
   * @return int
   */
  public function getDeliverFixLimit() {
    return $this->deliverFixLimit;
  }

  /**
   * @param int $deliverFixLimit
   */
  public function setDeliverFixLimit($deliverFixLimit) {
    $this->deliverFixLimit = $deliverFixLimit;
  }

  /**
   * @return boolean
   */
  public function isRebuildRequired() {
    return $this->rebuildRequired;
  }

  /**
   * @param boolean $rebuildRequired
   */
  public function setRebuildRequired($rebuildRequired) {
    $this->rebuildRequired = $rebuildRequired;
  }

  /**
   * @return boolean
   */
  public function isReady2Deliver() {
    return $this->ready2Deliver;
  }

  /**
   * @param boolean $ready2Deliver
   */
  public function setReady2Deliver($ready2Deliver) {
    $this->ready2Deliver = $ready2Deliver;
  }

  /**
   * Increments the fix count.
   */
  public function fixPP() {
    $this->fixCount++;
  }

  /**
   * Increments the build count.
   */
  public function builtPP() {
    $this->builtCount++;
  }
}