<?php

trait_require_once('oop_common');
trait_require_once('ki_dependent');
trait_require_once('ki_help');

/**
 * Class BuilderBase
 *
 * Base class to build data required by drupal available api's.
 */
class BuilderBase {

  use
    OopCommon,
    KiDependent,
    KiHelp {
    OopCommon::setUp as oopSetUp;
  }

  /*** INIT ***/

  /**
   * BuilderBase constructor.
   *
   * @param array $args
   *   The properties to set.
   */
  public function __construct(array $args = array()) {
    $this->setUp($args);
  }

  /**
   * Set up function.
   * Sets the object, and ensures he is ready to build.
   *
   * @param array $args
   *   The args to provide for the builder.
   */
  public function setUp($args = array()) {
    $this->oopSetUp($args);
    $this->autoSet();
  }

  /**
   * Init phase where construct args are set.
   *
   * @param array $args
   */
  protected function constructSet($args) {
    $this->setConstructArgs($args);
    $this->bulkSet($args);
  }

  /**
   * Auto sets properties.
   */
  protected function autoSet() {
  }

  /*** INIT END ***/

  /*** SETTERS AND GETTERS ***/
  /*** SETTERS AND GETTERS END ***/

  /*** EVAL METHODS ***/
  /*** EVAL METHODS ENDS ***/

  /*** PREPARE ***/
  /*** PREPARE END ***/

  /*** BUILD ***/
  /**
   * Build method.
   *
   * @return mixed
   */
  public function build() {
    $this->buildDefault();
    $this->kiBuildMethodCall();
  }

  /**
   * Default build method.
   *
   * @return mixed
   */
  protected function buildDefault() {
    if (($default = $this->kiGetDefaultValue($this->getKi())) !== NULL) {
      $processed = $this->processDefaultValue($default);
      $eval      = TRUE;
      if ($eval) {
        $this->getKi()->setTmpBuild($processed);
      }
      else {
        $processed = $this->processFallbacks();
        $this->getKi()->setTmpBuild($processed);
      }
    }
  }

  /**
   * Process a provided default value.
   *
   * @param mixed $default
   *   The default value to process.
   *
   * @return mixed
   */
  protected function processDefaultValue($default) {
    if (preg_match(RGX__WILDCARD, $default)) {
      return $this->getKi()->getTemplater()->process($default);
    }
  }

  /**
   * Processes the default value fallbacks.
   *
   * @return mixed
   */
  protected function processFallbacks() {
    $fallbacks = $this->getKi()->getDefaultFallbacks();
    for ($i = 0; $i < count($fallbacks); $i++) {

    }
  }

  /**
   * Retrieves and call a custom build method.
   *
   * @return mixed
   */
  protected function kiBuildMethodCall() {
    $scope  = $this->kiGetBuildMethodScope($this->getKi());
    $method = 'ki' . str2camelcase($this->getKi()->getName()) . 'Build';
    if (isset($scope)) {
      return $scope->$method();
    }
  }

  /*** BUILD END ***/

}