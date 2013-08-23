//
//  OAMapRendererView.h
//  OsmAnd
//
//  Created by Alexey Pelykh on 7/18/13.
//  Copyright (c) 2013 OsmAnd. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <OsmAndCore/CommonTypes.h>
#include <OsmAndCore/Map/MapTypes.h>
#include <OsmAndCore/Map/IMapBitmapTileProvider.h>
#include <OsmAndCore/Map/IMapElevationDataProvider.h>

@interface OAMapRendererView : UIView

- (void)createContext;
- (void)releaseContext;

@property (readonly) BOOL isRenderingSuspended;
- (BOOL)suspendRendering;
- (BOOL)resumeRendering;

- (std::shared_ptr<OsmAnd::IMapBitmapTileProvider>)providerOf:(OsmAnd::RasterMapLayerId)layer;
- (void)setProvider:(std::shared_ptr<OsmAnd::IMapBitmapTileProvider>)provider ofLayer:(OsmAnd::RasterMapLayerId)layer;
- (void)removeProviderOf:(OsmAnd::RasterMapLayerId)layer;
- (CGFloat)opacityOf:(OsmAnd::RasterMapLayerId)layer;
- (void)setOpacity:(CGFloat)opacity ofLayer:(OsmAnd::RasterMapLayerId)layer;
@property (nonatomic) std::shared_ptr<OsmAnd::IMapElevationDataProvider> elevationDataProvider;
- (void)removeElevationDataProvider;
@property (nonatomic) CGFloat elevationDataScale;
@property (nonatomic) CGFloat fieldOfView;
//virtual void setDistanceToFog(const float& fogDistance, bool forcedUpdate = false) = 0;
//virtual void setFogOriginFactor(const float& factor, bool forcedUpdate = false) = 0;
//virtual void setFogHeightOriginFactor(const float& factor, bool forcedUpdate = false) = 0;
//virtual void setFogDensity(const float& fogDensity, bool forcedUpdate = false) = 0;
//virtual void setFogColor(const FColorRGB& color, bool forcedUpdate = false) = 0;
//virtual void setSkyColor(const FColorRGB& color, bool forcedUpdate = false) = 0;
@property (nonatomic) CGFloat azimuth;
@property (nonatomic) CGFloat elevationAngle;
@property (nonatomic) OsmAnd::PointI target31;
@property (nonatomic) CGFloat zoom;
@property (nonatomic, readonly) OsmAnd::ZoomLevel zoomLevel;
@property (nonatomic, readonly) CGFloat scaledTileSizeOnScreen;

- (BOOL)convert:(CGPoint)point toLocation:(OsmAnd::PointI*)location;

@end
