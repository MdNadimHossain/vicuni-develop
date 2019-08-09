/**
 * @file
 * Grunt tasks.
 *
 * Run `grunt` for to process with dev settings.
 * Run `grunt prod` to process with prod settings.
 * Run `grunt watch` to start watching with dev settings.
 */

/* global module */
var VU_THEME_DIR = 'docroot/profiles/vicuni/themes/custom/vu';
var VICTORY_THEME_DIR = 'docroot/profiles/vicuni/themes/custom/victory';
var MODULES_DIR = 'docroot/profiles/vicuni/modules/custom';

module.exports = function (grunt) {
  'use strict';
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    eslint: {
      src: [
        'docroot/profiles/vicuni/modules/custom/**/*.js',
        '!docroot/profiles/vicuni/modules/custom/**/*.min.js',
        VU_THEME_DIR + '/**/*.js',
        '!' + VU_THEME_DIR + '/**/*.min.js',
        VICTORY_THEME_DIR + '/**/*.js',
        '!' + VICTORY_THEME_DIR + '/**/*.min.js',
        // Custom module excludes.
        '!docroot/profiles/vicuni/modules/custom/vumain/js/*.js',
        '!docroot/profiles/vicuni/modules/custom/vu_picasa/js/*.js',
        '!docroot/profiles/vicuni/modules/custom/vu_course_index/**/*.js',
        '!docroot/profiles/vicuni/modules/custom/vu_better_parent_item/resources/**/*.js',
        // Custom theme  excludes.
        '!' + VU_THEME_DIR + '/ckeditor.styles.js',
        '!' + VU_THEME_DIR + '/js/accordion.js',
        '!' + VU_THEME_DIR + '/js/facebook.js',
        '!' + VU_THEME_DIR + '/js/jquery.extlinks.js',
        '!' + VU_THEME_DIR + '/js/jquery.smoothscroll.js',
        '!' + VU_THEME_DIR + '/js.file-link-info.js',
        '!' + VU_THEME_DIR + '/js.sticky-header.js'
      ],
      options: {
        config: '.eslintrc.json',
        format: 'codeframe'
      }
    },
    sasslint: {
      options: {
        configFile: '.sass-lint.yml',
        formatter: 'codeframe',
        warningsAreErrors: true
      },
      target: [
        VU_THEME_DIR + '/**/*.scss',
        VICTORY_THEME_DIR + '/**/*.scss',
        'docroot/profiles/vicuni/modules/custom/**/*.scss'
      ]
    },
    sass_globbing: {
      dev: {
        files: {
          [VICTORY_THEME_DIR + '/scss/_bootstrap.scss']: VICTORY_THEME_DIR + '/scss/bootstrap/**/*.scss',
          [VICTORY_THEME_DIR + '/scss/_base.scss']: VICTORY_THEME_DIR + '/scss/base/**/*.scss',
          [VICTORY_THEME_DIR + '/scss/_component.scss']: VICTORY_THEME_DIR + '/scss/component/**/*.scss',
          [VICTORY_THEME_DIR + '/scss/_layout.scss']: VICTORY_THEME_DIR + '/scss/layout/**/*.scss',
          [VICTORY_THEME_DIR + '/scss/_debug.scss']: VICTORY_THEME_DIR + '/scss/debug/**/*.scss'
        },
        options: {
          useSingleQuotes: true,
          signature: '//\n// GENERATED FILE. DO NOT MODIFY DIRECTLY.\n//'
        }
      }
    },
    clean: [
      VU_THEME_DIR + '/build',
      VICTORY_THEME_DIR + '/build'
    ],
    concat: {
      options: {
        separator: '\n\n'
      },
      dist: {
        files: {
          [VU_THEME_DIR + '/build/js/vu.min.js']: [VU_THEME_DIR + '/js/*.js'],
          [VICTORY_THEME_DIR + '/build/js/victory.min.js']: [VICTORY_THEME_DIR + '/js/*.js']
        }
      }
    },
    uglify: {
      prod: {
        options: {
          mangle: {
            reserved: ['jQuery', 'Drupal']
          },
          compress: {
            drop_console: true
          }
        },
        files: {
          [VU_THEME_DIR + '/build/js/vu.min.js']: [VU_THEME_DIR + '/build/js/vu.min.js'],
          [VICTORY_THEME_DIR + '/build/js/victory.min.js']: [VICTORY_THEME_DIR + '/build/js/victory.min.js']
        }
      }
    },
    sass: {
      dev: {
        files: {
          [VU_THEME_DIR + '/build/css/vu.min.css']: VU_THEME_DIR + '/sass/styles.scss',
          [VICTORY_THEME_DIR + '/build/css/victory.min.css']: VICTORY_THEME_DIR + '/scss/style.scss',
          [MODULES_DIR + '/vu_rp/css/vu_rp.admin.min.css']: MODULES_DIR + '/vu_rp/css/vu_rp.admin.scss',
          [MODULES_DIR + '/vu_rp/css/vu_rp.form.min.css']: MODULES_DIR + '/vu_rp/css/vu_rp.form.scss'
        },
        options: {
          sourceMap: true,
          outputStyle: 'expanded',
          includePaths: [
            'node_modules/bootstrap-sass/assets/stylesheets/',
            'node_modules/breakpoint-sass/stylesheets/'
          ]
        }
      },
      prod: {
        files: {
          [VU_THEME_DIR + '/build/css/vu.min.css']: VU_THEME_DIR + '/sass/styles.scss',
          [VICTORY_THEME_DIR + '/build/css/victory.min.css']: VICTORY_THEME_DIR + '/scss/style.scss',
          [MODULES_DIR + '/vu_rp/css/vu_rp.admin.min.css']: MODULES_DIR + '/vu_rp/css/vu_rp.admin.scss',
          [MODULES_DIR + '/vu_rp/css/vu_rp.form.min.css']: MODULES_DIR + '/vu_rp/css/vu_rp.form.scss'
        },
        options: {
          sourceMap: false,
          outputStyle: 'compressed',
          includePaths: [
            'node_modules/bootstrap-sass/assets/stylesheets/',
            'node_modules/breakpoint-sass/stylesheets/'
          ]
        }
      }
    },
    postcss: {
      options: {
        processors: [
          require('autoprefixer')({browsers: ['last 2 versions', 'not ie <= 8', 'iOS >= 7']})
        ]
      },
      dev: {
        map: true,
        src: [
          VU_THEME_DIR + '/build/css/vu.min.css',
          VICTORY_THEME_DIR + '/build/css/victory.min.css'
        ]
      },
      prod: {
        map: false,
        src: [
          VU_THEME_DIR + '/build/css/vu.min.css',
          VICTORY_THEME_DIR + '/build/css/victory.min.css'
        ]
      }
    },
    copy: {
      images: {
        files: [
          {
            expand: true,
            cwd: VU_THEME_DIR + '/images/',
            src: '**',
            dest: VU_THEME_DIR + '/build/images'
          },
          {
            expand: true,
            cwd: VICTORY_THEME_DIR + '/images/',
            src: '**',
            dest: VICTORY_THEME_DIR + '/build/images'
          },
          {
            expand: true,
            cwd: VICTORY_THEME_DIR + '/fonts/',
            src: '**',
            dest: VICTORY_THEME_DIR + '/build/fonts'
          }
        ]
      }
    },
    watch: {
      scripts: {
        files: [
          VU_THEME_DIR + '/js/**/*.js',
          VICTORY_THEME_DIR + '/js/**/*.js'
        ],
        tasks: ['concat'],
        options: {
          spawn: false
        }
      },
      styles: {
        files: [
          VU_THEME_DIR + '/scss/**/*.scss',
          VICTORY_THEME_DIR + '/scss/**/*.scss'
        ],
        tasks: ['sass_globbing', 'sass:dev', 'postcss:dev'],
        options: {
          livereload: true,
          spawn: false
        }
      }
    }
  });

  grunt.loadNpmTasks('grunt-postcss');
  grunt.loadNpmTasks('grunt-sass-globbing');
  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('gruntify-eslint');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-sass-lint');
  grunt.loadNpmTasks('grunt-exec');

  grunt.registerTask('lint', ['eslint', 'sasslint']);
  grunt.registerTask('prod', ['lint', 'sass_globbing', 'clean', 'concat', 'uglify:prod', 'sass:prod', 'postcss:prod', 'copy']);
  grunt.registerTask('dev', ['sass_globbing', 'clean', 'concat', 'sass:dev', 'postcss:dev', 'copy']);
  // By default, run grunt with prod settings.
  grunt.registerTask('default', ['prod']);
};
