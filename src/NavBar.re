let component = ReasonReact.statelessComponent("NavBar");

let make = _children => {
  ...component,
  render: _self => MaterialUi.(
        <div>
          <MaterialUi.AppBar position=`Static >
            <MaterialUi.Toolbar >
              <MaterialUi.Typography variant=`Title color=`Inherit>
              (ReasonReact.string("React & Material-UI Sample Application"))
              </MaterialUi.Typography>
            </MaterialUi.Toolbar>
          </MaterialUi.AppBar>
        </div>
      ),
};
