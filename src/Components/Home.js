function Home() {
    return (
      <>
<div id="content"> 
  {/* licens */}
  <div className="licens">
    <div className="container">
      <div className="row">
        <div className="col-md-12">
          <div className="titlepage">
            <h2>Our Games</h2>
            <span />
          </div>
        </div>
      </div>
      <div className="row">
        <div className="col-md-12">
          <div id="licens" className="carousel slide licens_Carousel " data-ride="carousel">
            <ol className="carousel-indicators">
              <li data-target="#licens" data-slide-to={0} className="active" />
              <li data-target="#licens" data-slide-to={1} />
              <li data-target="#licens" data-slide-to={2} />
            </ol>
            <div className="carousel-inner">
              <div className="carousel-item active">
                <div className="container">
                  <div className="carousel-caption ">
                    <div className="row d_flex">
                      <div className="col-md-6">
                        <div className="test_box">
                          <div className="jons">
                            <h4>Mines</h4>
                          </div>
                          <p>In this game, there are stars and land mines hidden on the field. Goal is to open as many stars as possible and don’t blow up on the mine. With each opened star winnings increase. Player can cash out after each successful guess and take his winnings.</p>
                        </div>
                      </div>
                      <div className="col-md-6">
                        <div className="test_box">
                          <div className="jons">
                            <figure><img src="images/jons_img1.png" alt="#" /></figure>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="carousel-item">
                <div className="container">
                  <div className="carousel-caption">
                    <div className="row d_flex">
                      <div className="col-md-6">
                        <div className="test_box">
                          <div className="jons">
                            <h4>Roulette</h4>
                          </div>
                          <p>Roulette is a game where there is a wheel and a ball is dropped in, the ball can land on red, black or green and certain numbers associated with each slot. The player is able to place bets by placing chips on either black, red, or green in trying to choose what color the ball will land on.</p>
                        </div>
                      </div>
                      <div className="col-md-6">
                        <div className="test_box">
                          <div className="jons">
                            <figure><img src="images/jons_img1.png" alt="#" /></figure>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="carousel-item">
                <div className="container">
                  <div className="carousel-caption">
                    <div className="row d_flex">
                      <div className="col-md-6">
                        <div className="test_box">
                          <div className="jons">
                            <h4>Coin Flip</h4>
                          </div>
                          <p>Coin flip is a game where the user places money on whether they believe the coin will land heads side up or tails side up. The point of the game is to simply flip a coin and see which side is facing up. The only rules are that the user cannot touch or alter the coin once flipped.</p>
                          
                        </div>
                      </div>
                      <div className="col-md-6">
                        <div className="test_box">
                          <div className="jons">
                            <figure><img src="images/jons_img1.png" alt="#" /></figure>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <a className="carousel-control-prev" href="#licens" role="button" data-slide="prev">
              <i className="fa fa-long-arrow-left" aria-hidden="true" />
            </a>
            <a className="carousel-control-next" href="#licens" role="button" data-slide="next">
              <i className="fa fa-long-arrow-right" aria-hidden="true" />
            </a>
          </div>
          <p className="lorem"></p>
        </div>
        <div id="about" className="col-md-12">
          <ul className="spinit">
            <li><a href="Javascript:void(0)">About TMT</a></li>
          </ul>
          <div className="two_box">
            <div className="row d_flex">
              <div className="col-md-4">
                <div className="many_box_img">
                  <figure><img src="images/game3.jpg" alt="#" /></figure>
                </div>
              </div>
              <div className="col-md-8">
                <div className="many_box">
                  <p>
                  The Money Team (TMT) is a dynamic online platform founded by a team of forward-thinking individuals including Adem Durakovic, Amar Hadzic, Jack Mcphillips, and Nhi Tran. 
                  With a passion for innovation and a commitment to providing thrilling entertainment, TMT offers a diverse range of gambling games, including Mines, Roulette, and Coin Flip. 
                  Our developers have meticulously crafted these games to ensure seamless functionality and an immersive user experience. 
                  At TMT, we strive to create an environment where players can enjoy the excitement of gaming while also fostering a sense of community. 
                  Join us today and experience the thrill of winning with TMT!
                  </p>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  {/* end lLicens */}
  
  {/* reqeste */}
  <div id="contact" className="reqeste">
    <div className="container">
      <div className="row">
        <div className="col-md-12">
          <div className="titlepage">
            <h2>Send Us A Message</h2>
            <span />
          </div>
        </div>
      </div>
      <div className="row">
        <div className="col-md-6 offset-md-3">
          <form id="cochang" className="form_main">
            <div className="row">
              <div className="col-md-12">
                <input className="form_control" placeholder="Name" type="text" name="Name" />
              </div>
              <div className="col-md-12">
                <input className="form_control" placeholder="Phone number" type="text" name="Phone number" />
              </div>
              <div className="col-md-12">
                <input className="form_control" placeholder="Email" type="text" name="Email" />
              </div>
              <div className="col-md-12">
                <input className="form_control" placeholder="Message" type="text" name="Message" />
              </div>
              <div className="col-md-12">
                <button className="send_btn">Send</button>
              </div>
            </div>
          </form>
        </div>
      </div>
    </div>
  </div>
</div>

      </>
    );
  }
  
  export default Home;