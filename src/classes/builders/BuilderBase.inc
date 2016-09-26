<?php

require_once OOP_PATH . '/src/traits/OopCommon.inc';
require_once OOP_PATH . '/src/traits/dependencies/HelperDependent.inc';

/**
 * Class BuilderBase
 *
 * Base class to build data required by drupal available api's.
 */
class BuilderBase_ {

  use OopCommon,
    HelperDependent {
    OopCommon::setUp as oopSetUp;
    HelperDependent::getHelper as hlpr;
  }

  /*** INIT ***/

  /**
   * BuilderBase constructor.
   *
   * @param array $args
   *   The properties to set.
   *
   * @throws EntityToolboxException
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
    $this->autoSetHelper();
  }

  /**
   * Auto sets the main helper.
   */
  protected function autoSetHelper() {
    $helper = $this->helperGetInstance('Builder');
    $this->setHelper($helper);
  }

  /*** INIT END ***/

  /*** SETTERS AND GETTERS ***/
  /*** SETTERS AND GETTERS END ***/

  /*** EVAL METHODS ***/
  /*** EVAL METHODS ENDS ***/

  /*** PREPARE ***/
  /*** PREPARE END ***/

}