module MenuIcon = MscharleyBsMaterialUiIcons.Menu;
module ChevronLeftIcon = MscharleyBsMaterialUiIcons.ChevronLeft;
module InboxIcon = MscharleyBsMaterialUiIcons.Inbox;

module L = List;

open MaterialUi;

type state = {
  message : string,
  opened : bool
};

type action =
  | DrawerClicked
  | IconButtonClicked;


/* This is the basic component. */
let component = ReasonReact.reducerComponent("PersistentDrawerLeft");

/* Your familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = (_event, _self) => Js.log("clicked!");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */

[%mui.withStyles
   "StyledPersistentDrawerLeft"({
     root:
       ReactDOMRe.Style.make(~display="flex", ()),
     alignRight:
       ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ()),
     
   })
];

 
let make = (~message, children) => {
  ...component,
  initialState: () => {
    message : message,
    opened : false
  },
  reducer: (action, {message, opened}) => 
      switch action {
      | IconButtonClicked => ReasonReact.Update({message, opened: !opened})
      | DrawerClicked => ReasonReact.Update({message, opened: false})
      },
  render: self =>
    <StyledPersistentDrawerLeft
      render={ classes =>
      <div className={classes.root}>
        <CssBaseline />
        <AppBar position=`Fixed>
          <Toolbar disableGutters=(!self.state.opened)>
            <IconButton color=`Inherit onClick=(_event => self.send(IconButtonClicked)) >
              <MenuIcon.Filled />
            </IconButton>
            <Typography variant=`H6 color=`Inherit>
              (ReasonReact.string("Persistent drawer"))
            </Typography>
          </Toolbar>
        </AppBar>
        <Drawer variant=`Persistent anchor=`Left open_=self.state.opened>
          <div>
            <IconButton onClick=(_event => self.send(DrawerClicked))>
              <ChevronLeftIcon.Filled />
            </IconButton>
          </div>
          <Divider />
          <List>
          (
            ["Inbox", "Starred", "Send email", "Drafts"]
            |> L.map (item =>
                <ListItem button=true key=item>
                  <ListItemIcon> <InboxIcon.Filled /> </ListItemIcon>
                  <ListItemText primary=ReasonReact.string(item) />
                </ListItem>
               ) 
            |> Array.of_list
            |> ReasonReact.array
          )  
          </List>
          <Divider />
          <List>
          </List>
        </Drawer>
        <main>
          <div/>
          <Typography>
            (ReasonReact.string("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor
            incididunt ut labore et dolore magna aliqua. Rhoncus dolor purus non enim praesent
            elementum facilisis leo vel. Risus at ultrices mi tempus imperdiet. Semper risus in
            hendrerit gravida rutrum quisque non tellus. Convallis convallis tellus id interdum
            velit laoreet id donec ultrices. Odio morbi quis commodo odio aenean sed adipiscing.
            Amet nisl suscipit adipiscing bibendum est ultricies integer quis. Cursus euismod quis
            viverra nibh cras. Metus vulputate eu scelerisque felis imperdiet proin fermentum leo.
            Mauris commodo quis imperdiet massa tincidunt. Cras tincidunt lobortis feugiat vivamus
            at augue. At augue eget arcu dictum varius duis at consectetur lorem. Velit sed
            ullamcorper morbi tincidunt. Lorem donec massa sapien faucibus et molestie ac."))
          </Typography>
          <Typography>
            (ReasonReact.string("Consequat mauris nunc congue nisi vitae suscipit. Fringilla est ullamcorper eget nulla
            facilisi etiam dignissim diam. Pulvinar elementum integer enim neque volutpat ac
            tincidunt. Ornare suspendisse sed nisi lacus sed viverra tellus. Purus sit amet volutpat
            consequat mauris. Elementum eu facilisis sed odio morbi. Euismod lacinia at quis risus
            sed vulputate odio. Morbi tincidunt ornare massa eget egestas purus viverra accumsan in.
            In hendrerit gravida rutrum quisque non tellus orci ac. Pellentesque nec nam aliquam sem
            et tortor. Habitant morbi tristique senectus et. Adipiscing elit duis tristique
            sollicitudin nibh sit. Ornare aenean euismod elementum nisi quis eleifend. Commodo
            viverra maecenas accumsan lacus vel facilisis. Nulla posuere sollicitudin aliquam
            ultrices sagittis orci a."))
          </Typography>
        </main>
      </div>
    }
  />,
};
