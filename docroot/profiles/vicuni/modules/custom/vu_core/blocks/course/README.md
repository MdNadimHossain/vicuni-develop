# How to Apply block system.

All blocks in this directory are for the How to Apply block system.

The files need to conform to set rules:

1. The class name must be a CamelCase version of the
   file name with `VuCore` prepended and `CourseBlock` appended.
   
   e.g. `file_name.inc` -> `VuCoreFileNameCourseBlock()`

2. All blocks require a `public static $info` to be set,
   which is the human readable name of the block.

3. All blocks require a `public $theme` item to be set,
   which is the theme item that will be rendered on view.



## Conditions

### Fields

The following fields can be set to define the display conditions of a block.

See http://php.net/manual/en/language.operators.bitwise.php for more information
on bitwise operators.

- **Audience:** `public $condAudience`  
   
  Available options:
  - `VU_HTA_AUDIENCE_DOMESTIC` - Domestic.
  - `VU_HTA_AUDIENCE_INTERNATIONAL` - International.
  - `VU_HTA_AUDIENCE_ALL` _(default)_ - Any audience.


- **Course AQF level**: `public $condAQF`
   
  See `/vu_core/classes/course_blocks.inc#23-84` for available options.


- **Course intake state:** `public $condOpen`
   
  Available options:
  - `VU_CBS_OPEN_YES` - Course is open for intake.
  - `VU_CBS_OPEN_NO` - Course is not open for intake.
  - `VU_CBS_OPEN_IGNORE` _(default)_ - Ignore course intake state.


- **Course type:** `public $condType`

  Available options:
  - `VU_CBS_TYPE_HE` - Higher education.
  - `VU_CBS_TYPE_NA` - Non-award.
  - `VU_CBS_TYPE_VE` - VET.
  - `VU_CBS_TYPE_ALL` _(default) - All.


### Methods

- `public function condCallback() {}`

  Any custom logic can be added by defining this method, which needs tor return
  a boolean TRUE or FALSE.



## Output

- `public $theme`

  Set any Drupal theme item here for use in `theme('[YOUR ITME]')` for the
  output of your block.


- `public function variables() {}`

  If the above `$theme` item requires variables, defined this method and return
  an array of your required variables.



## Example

`file_name.inc`:
```php
/**
 * Class VuCoreFileNameCourseBlock.
 */
class VuCoreFileNameCourseBlock extends VuCoreCourseBlockBase {

  /**
   * {@inheritdoc}
   */
  public $condAQF = VU_CBS_AQF_GROUP_ALL;

  /**
   * {@inheritdoc}
   */
  public $condAudience = VU_CBS_AUDIENCE_DOMESTIC;

  /**
   * {@inheritdoc}
   */
  public $condType = VU_CBS_TYPE_ALL;

  /**
   * {@inheritdoc}
   */
  public $condOpen = VU_CBS_OPEN_YES;

  /**
   * {@inheritdoc}
   */
  public static $info = 'Test block';

  /**
   * {@inheritdoc}
   */
  public $theme = 'vu_course_international_brochure';

  /**
   * {@inheritdoc}
   */
  public function variables() {
    return [
      'link' => 'http://vu.edu.au',
    ];
  }

}
```
