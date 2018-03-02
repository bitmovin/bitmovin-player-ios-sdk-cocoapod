Pod::Spec.new do |s|      
    s.name = 'BitmovinPlayer'
    s.version = '2.6.2'
    s.summary = 'Bitmovin Player SDK for iOS and tvOS'
    s.homepage = 'https://www.bitmovin.com/'
    s.social_media_url = 'https://twitter.com/bitmovin'
    s.documentation_url = 'https://www.bitmovin.com/'
    s.author = { 'Bitmovin' => 'support@bitmovin.com' }
    s.license = { :type => "Commercial", :file => "LICENSE.md" }
    s.source = { :git => "https://github.com/bitmovin/bitmovin-player-ios-sdk-cocoapod.git", :tag => s.version.to_s }

    s.ios.deployment_target = '9.0'
    s.ios.vendored_frameworks = 'iOS/BitmovinPlayer.framework'
    s.ios.frameworks = [ 
        'Foundation', 
        'UIKit', 
        'AVFoundation', 
        'AVKit', 
        'WebKit'
    ]
    
    s.tvos.deployment_target = '9.0'
    s.tvos.vendored_frameworks = 'tvOS/BitmovinPlayer.framework'
    s.tvos.frameworks = [ 
        'Foundation', 
        'UIKit',
        'AVFoundation', 
        'AVKit'
    ] 
end
