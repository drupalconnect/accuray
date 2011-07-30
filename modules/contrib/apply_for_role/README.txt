$Id: README.txt,v 1.3 2008/02/27 14:58:33 svilen Exp $

        APPLY_FOR_ROLE MODULE - README
______________________________________________________________________________

NAME:       Apply_for_role
AUTHORS:    Svilen Sabev <svilensabev@gmail.com>
______________________________________________________________________________


------------
Description
------------

This module allows users to apply for a role and administrators to approve their application. 
The role will be automatically assigned to the user on approval.

------------
Requirements
------------

- Drupal 6

------------
Installation
------------

Step 1) Download latest release from http://drupal.org/project/apply_for_role

Step 2)
  Extract the package into your 'modules' directory.

Step 3)
  Enable the apply_for_role module.

  Go to "administer >> build >> modules" and put a checkmark in the 'status' column next
  to 'apply_for_role'.

Step 4)
  Go to "administer >> site configuration >> apply for role" to configure the module.


Step 5)
  Enable permissions appropriate to your site.
  The apply_for_role module provides three permissions:
	- 'administer apply for role'
	- 'apply for role'
	- 'approve apply for role'

------------
Usage
------------

Step 1)
  Go to "my account" >> "apply for role" to apply for role.

Step 2)
  Go to "administer >>  user management >> apply for role" to manage the user applications.

------------
Credits
------------

Originally written and maintained by Svilen Sabev for www.propeople.dk
