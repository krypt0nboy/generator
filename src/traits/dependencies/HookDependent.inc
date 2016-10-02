<?php

/**
 * Class HookDependent
 */
trait HookDependent {
  /**
   * @access protected
   * @var string $hook
   *   The hook's name.
   */
  protected $hook;
  /**
   * @access protected
   * @var array $hookInfo
   *   The hook's info.
   */
  protected $hookInfo = array();

  /**
   * @return string
   */
  public function getHook() {
    return $this->hook;
  }

  /**
   * @param string $hook
   */
  public function setHook($hook) {
    $this->hook = $hook;
  }

  /**
   * @return array
   */
  public function getHookInfo() {
    return $this->hookInfo;
  }

  /**
   * @param array $hookInfo
   */
  public function setHookInfo($hookInfo) {
    $this->hookInfo = $hookInfo;
  }
}