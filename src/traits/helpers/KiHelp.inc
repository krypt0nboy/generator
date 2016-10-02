<?php

/**
 * Class KiHelp
 */
trait KiHelp {

  /*** SETTERS AND GETTERS ***/

  /**
   * Returns an instance of KiBase.
   *
   * @param array $args
   *   The args to pass to the factory.
   *
   * @return KiBase
   */
  public function kiGetInstance(array $args = array()) {
    $ki = factory('ki')
      ->getInstance($args);

    return $ki;
  }

  /**
   * Returns the Ki default value.
   *
   * @param KiBase $ki
   *   The Ki.
   *
   * @return mixed
   */
  public function kiGetDefaultValue($ki) {
    return $ki->getDefault();
  }

  /**
   * Returns the scope in which the build method is available.
   *
   * @param KiBase $ki
   *   The Ki.
   *
   * @return mixed
   */
  public function kiGetBuildMethodScope($ki) {
    $method = 'ki' . str2camelcase($ki->getName()) . 'Build';
    if (method_exists($ki, $method)) {
      return $ki;
    }
    else {
      if (method_exists($ki->getBuilder(), $method)) {
        return $ki->getBuilder();
      }
      else {
        if ($ki->__isset('parent_ki')) {
          if (method_exists($ki->getParentKi(), $method)) {
            return $ki->getParentKi();
          }
        }
      }
    }
  }

  /*** SETTERS AND GETTERS END ***/

  /*** HASSERS ***/

  /**
   * Checks if a Ki has a default value.
   *
   * @param KiBase|StaticKiBase $ki
   *   The Ki.
   *
   * @return bool
   */
  public function kiHasDefaultValue($ki) {
    return $ki->__isset('default_value');
  }

  /**
   * Checks if a Ki has a default value.
   *
   * @param KiBase|StaticKiBase $ki
   *   The Ki.
   *
   * @return bool
   */
  public function kiHasDefaultValueFallbacks($ki) {
    return $ki->__isset('default_fallbacks');
  }

  /**
   * Checks if a Ki has unset conditions.
   *
   * @param KiBase|StaticKiBase $ki
   *   The Ki.
   *
   * @return bool
   */
  public function kiHasUnsetConditions($ki) {
    return $ki->__isset('unset_conditions');
  }

  /*** HASSERS END ***/

  /*** ISSERS ***/
  /*** ISSERS END ***/

  /*** EVAL METHODS ***/

  /*** EVAL METHODS ENDS ***/
}