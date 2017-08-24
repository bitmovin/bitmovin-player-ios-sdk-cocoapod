Pod::Spec.new do |s|      
    s.name = 'BitmovinPlayer'
    s.version = '1.2.0'
    s.summary = 'Bitmovin Player SDK for iOS'
    s.homepage = 'https://www.bitmovin.com/'
    s.social_media_url = 'https://twitter.com/bitmovin'
    s.documentation_url = 'https://www.bitmovin.com/'
    s.author = { 'Bitmovin' => 'support@bitmovin.com' }
    s.license = { :type => "Commercial", :file => "LICENSE.md" }
    s.platform = :ios
    s.source = { :git => "https://github.com/bitmovin/bitmovin-player-ios-sdk-cocoapod.git", :tag => s.version.to_s }
    s.ios.deployment_target = '9.0'
    s.vendored_frameworks = 'BitmovinPlayer.framework'
    s.frameworks = [ 
        'Foundation', 
        'UIKit', 
        'AVFoundation', 
        'AVKit', 
        'WebKit'
    ]    
end
