function Footer() {
    return (
    <>
      <div id="content">
        <footer>
          <div className="footer">
            <div className="container">
              <div className="row">
                <div className="col-xl-6 col-lg-6 col-md-6 col-sm-12 ">
                  <div className="address">
                    <h3>Let's keep in touch</h3>
                      <form className="newtetter">
                        <button className="submit">Subscribe</button>
                        <input className="tetter" placeholder="Enter your email" type="text" name="Enter your email" />
                      </form>
                  </div>
                </div>
                <div className="col-xl-6 col-lg-6 col-md-6 col-sm-12">
                  <div className="row">
                    <div className="col-xl-6 col-lg-6 col-md-6 col-sm-6">
                      <div className="address">
                        <h3>Links</h3>
                        <ul className="Menu_footer">
                          <li className="active"> <a href="index.html">Home</a> </li>
                          <li><a href="#licens">Game</a> </li>
                          <li><a href="#about">About Us</a> </li>
                          <li><a href="#contact">Contact</a> </li>
                        </ul>
                      </div>
                    </div>
                    <div className="col-xl-6 col-lg-6 col-md-6 col-sm-6">
                      <div className="address">
                        <h3>Contact us</h3>
                          <ul className="Links_footer">
                            <li>hello@tmt.co</li>
                          </ul>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div className="copyright">
              <div className="container">
                <p>Copyright 2024 All Right Reserved By <a href="index.html">The TMT</a></p>
              </div>
            </div>
          </div>
        </footer>
      </div>
    </>
    );
}
export default Footer;