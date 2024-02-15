function Header() {
  return (
    <>
<div>
  {/* end loader */}
  <div id="content">
    {/* header */}
    <header>
      {/* header inner */}
      <div className="head_top">
        <div className="header">
          <div className="container-fluid">
            <div className="row">
              <div className="col-md-3 logo_section">
                <div className="full">
                  <div className="center-desk">
                    <div className="logo">
                      <a href="index.html"><img src="images/logo.png" alt="#" /></a>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </header>
    <section className="slider_section">
  <div className="banner_main">
    <img src="images/bg_main.jpg" alt="#" />
    <div className="container-fluid padding3">
      <div className="row">
        <div className="col-md-12">
          <div className="text-bg">
            <a href="Javascript:void(0)">Enter game room</a>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>

  </div>
</div>

    </>
  );
}

export default Header;