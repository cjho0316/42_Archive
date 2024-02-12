<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'jang-cho' );

/** Database password */
define( 'DB_PASSWORD', '123123' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '$AX5xv>BB+7/^Lc/hdp!wq}cOS||o[twP|PZ?zM/0uWIo+ZbWB(V3{]v|&|-1([`');
define('SECURE_AUTH_KEY',  'X^2ef<Za{[mq~H9/*? ijC6i~C6ioJ}OKXOYv E+{8Y<D=2BA,.SQ``M7Rz027oc');
define('LOGGED_IN_KEY',    '`Np sS]Rp,~ V}zLmg y:0kcR6<o*bx26T6K;T^3L2vM}y~2%@Wg-+j$9$-HOz{.');
define('NONCE_KEY',        '%]]4N:M;E+2&pRD5WA:O*u~^xI=|/=]|@Bt9).h1$^joI4AS]c>}FH/%YO<^j|jk');
define('AUTH_SALT',        'm)F9>R,(m^;/!h|V>B|*9G.3DJz-&g%|oeWn;uGyD.9um,o.;R6-+:+2/ah>4,/]');
define('SECURE_AUTH_SALT', '-6cioF/AdEICTF>*1j*m5i>[`0D-uV,*CP^biS/T;)]oZ|stR+ RPm|)dS%1A8|p');
define('LOGGED_IN_SALT',   'I#7tV+1e=p@Wg;.8$K0Jn)Ng3@Bt2mQmv|Hyc%oQ&NG}dRVUX4Zm/L_59B[&D$n>');
define('NONCE_SALT',       'R,WZ4yk6xq3S !Fe@nxAbK`Nw9t>,l-1i~Lc]rKgb&*b#&0IDws*7C*%K`hXhj7c');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
