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
   * Returns a builder instance.
   *
   * @param string $name
   * @param array  $args
   *
   * @return BuilderBase
   */
  public function builderGetInstance($name, array $args = array()) {
    $factory = new BuilderFactory();

    return $factory->getInstance($args);
  }
}