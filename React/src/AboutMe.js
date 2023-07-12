import React from 'react'
import ReactPlayer from 'react-player'
function AboutMe()
{
return(
    <div className="live_feed">
    <div className='player-wrapper'>
        <ReactPlayer
            className='react-player fixed-bottom'
            url= 'videos/draj1.MP4'
            width='45%'
            height='100%'
            controls = {true}

        /> <ReactPlayer
            className='react-player fixed-bottom'
            url= 'videos/draj2.MP4'
            width='45%'
            height='100%'
            controls = {true}

        /></div>
        <div className="livefeed">
            <h1>Here you can watch the live feed</h1>
        </div></div>
    );
}
export default AboutMe;