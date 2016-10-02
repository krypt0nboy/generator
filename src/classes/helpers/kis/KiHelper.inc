<?php

require_once GENERATOR_PATH . '/src/classes/helpers/GeneratorsCommonHelper.inc';


/**
 * Class KiHelper
 */
class KiHelper extends GeneratorsCommonHelper {

  /*** SETTERS AND GETTERS ***/

  /*** SETTERS AND GETTERS END ***/

  /*** HASSERS ***/

  /**
   * Checks if the data holder has unset conditions.
   *
   * @return bool
   */
  public function hasUnsetConditions() {
    return $this->getDataHolder()->__isset('unset_conditions');
  }

  /*** HASSERS END ***/

  /*** ISSERS ***/
  /*** ISSERS END ***/

  /*** EVAL METHODS ***/
  /*** EVAL METHODS ENDS ***/
}