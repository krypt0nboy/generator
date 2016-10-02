<?php

/**
 * Class BuilderDependent
 */
trait BuilderDependent {
  /**
   * @access protected
   * @var BuilderBase $builder
   *   The object's builder.
   */
  protected $builder;
  /**
   * @access protected
   * @var array $builderInstanceArgs
   *   The args to pass to the builder when instanciating it.
   */
  protected $builderInstanceArgs = array();

  /**
   * @return BuilderBase
   */
  public function getBuilder() {
    return $this->builder;
  }

  /**
   * @param BuilderBase $builder
   */
  public function setBuilder(BuilderBase $builder) {
    $this->builder = $builder;
  }

  /**
   * @return array
   */
  public function getBuilderInstanceArgs() {
    return $this->builderInstanceArgs;
  }

  /**
   * @param array $builderInstanceArgs
   */
  public function setBuilderInstanceArgs($builderInstanceArgs) {
    $this->builderInstanceArgs = $builderInstanceArgs;
  }

  /**
   * Returns a builder instance.
   *
   * @param string $builder_sys_id
   * @param array  $args
   *
   * @return BuilderBase
   */
  public function builderGetInstance($builder_sys_id, array $args = array()) {
    $args = $this->mergeArgs(array('instance_args' => $this->builderInstanceArgs), $args);

    return builder($builder_sys_id, $args);
  }
}