# Comment Publish

Comment Publish adds granular permissions for publishing, unpublishing, and
editing comments. Core bundles all comment moderation into the single
"Administer comments" permission, which also allows deleting any comment on
the site. This module allows site builders to grant editors and moderators
just the abilities they need without also giving them delete access.

## Requirements

This module requires that the following modules are also enabled:

- Comment (Backdrop core)

## Installation

- Install this module using the official Backdrop CMS instructions at
<https://docs.backdropcms.org/documentation/extend-with-modules>.

- Visit the permissions page under Administration > Configuration > User
Accounts > Permissions (admin/config/people/permissions) and grant the
appropriate permissions to editor or moderator roles (see below).

## Permissions

This module provides three permissions:

- **Publish comments** - publish unapproved or previously unpublished
comments.
- **Unpublish comments** - unpublish published comments.
- **Edit any comment** - edit the text of any comment, including those
posted by other users. Grant only to highly trusted roles.

Each permission carries the access needed to act on it:

- Holders of any of the three permissions can access both comment admin
overview tabs at Administration > Content > Comments
(admin/content/comment). The tab they can act on shows the relevant bulk
operation; the other is view-only.
- Holders of any of the three permissions can see unpublished comments
when viewing nodes, so they can act on them where they encounter them.
- Holders of "Publish comments" see an approve action link on unpublished
comments when viewing nodes.
- Holders of "Unpublish comments" see an unpublish action link on
published comments when viewing nodes.
- Holders of "Edit any comment" can reach the comment edit page and see
an edit action link on comments when viewing nodes. The comment edit form
shows a read-only Administration fieldset with author name, email,
homepage, date, and status — the context needed for informed moderation.
Status is editable for users who also hold "Publish comments" or
"Unpublish comments".

Deleting comments always requires the full "Administer comments"
permission.

## Recommended permissions for editors and moderators

The three permissions this module provides can be granted independently,
but granting all three together gives editors and moderators the most
complete experience: they can publish, unpublish, and edit comments, and
through the edit form they can also see the author details needed to make
informed moderation decisions.

To allow a role to fully moderate comments on the site, grant the following
permissions:

- **Publish comments** (this module)
- **Unpublish comments** (this module)
- **Edit any comment** (this module)
- **View user profiles** (Backdrop core) - required to follow the linked
username shown in the Administration fieldset on the comment and comment edit
form.

## Issues

Bugs and feature requests should be reported in [the Issue Queue](https://github.com/backdrop-contrib/comment_publish/issues).

## Current Maintainers

- [izmeez](https://github.com/izmeez).
- Seeking additional maintainers.

## Credits

- Developed for Backdrop CMS by [izmeez](https://github.com/izmeez). Assisted-by: LLM agent.

## License

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
