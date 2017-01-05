/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 19 Sep 2014 7:23:32pm
    Author:  Joshua Marler

  ==============================================================================
*/

#include "CustomLookAndFeel.h"

//===============================================================================

//Basic override of drawRotarySlider function

/*
    Uses path data from SVG to path data conversion tool in Introjucer/Projucer - works best if the SVG file used is composed of a
    single vector / path. Change the pathData[] variable to whatever path data the SVG conversion tool spits out at you.
 
    Pay attention to this line in the drawRotarySlider function  -  svgPath.scaleToFit(-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f, true);
 
    This line scales the converted SVG path to fit inside the rotary sliders outer arc/circle. This is necessary only for this particular slider style and could be changed. 
*/

void CustomLookAndFeel::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                       const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    const auto radius = jmin (width / 2, height / 2) - 2.0f;
    const auto centreX = x + width * 0.5f;
    const auto centreY = y + height * 0.5f;
    const auto rx = centreX - radius;
    const auto ry = centreY - radius;
    const auto rw = radius * 2.0f;
    const auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    const auto isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
    
    if (radius > 12.0f)
    {
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 1.0f : 0.7f));
        else
            g.setColour (Colour (0x80808080));
        
        const auto thickness = 0.75f;
        
        {
            Path filledArc;
            filledArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, angle, thickness);
            
            g.fillPath (filledArc);
        }
        
        if (thickness > 0)
        {
            const auto innerRadius = radius * 0.5f;
            Path p;
            
            
            static const unsigned char pathData[] = { 110,109,102,38,152,67,154,25,94,67,98,51,115,152,67,154,25,94,67,0,192,152,67,52,51,94,67,204,12,153,67,205,76,94,67,98,102,230,152,67,205,76,94,67,204,204,152,67,205,76,94,67,204,204,152,67,205,76,94,67,98,102,166,152,67,205,76,94,67,204,12,154,67,51,
                179,94,67,102,38,154,67,51,179,94,67,98,153,217,154,67,102,230,94,67,0,128,155,67,102,102,95,67,51,51,156,67,51,179,95,67,98,205,140,157,67,102,102,96,67,205,204,158,67,102,102,97,67,153,25,160,67,102,102,98,67,98,51,51,160,67,0,128,98,67,204,12,161,
                67,204,76,99,67,204,76,161,67,0,128,99,67,98,50,243,161,67,51,51,100,67,204,140,162,67,102,230,100,67,50,51,163,67,154,153,101,67,98,152,89,164,67,103,230,102,67,50,115,165,67,0,128,104,67,204,140,166,67,52,51,106,67,98,255,191,166,67,103,102,106,67,
                153,217,166,67,154,153,106,67,50,243,166,67,206,204,106,67,98,255,255,166,67,104,230,106,67,204,12,167,67,1,0,107,67,152,25,167,67,155,25,107,67,98,152,153,167,67,1,0,108,67,152,25,168,67,1,0,109,67,203,140,168,67,104,230,109,67,98,254,127,169,67,206,
                204,111,67,101,102,170,67,206,204,113,67,254,63,171,67,2,0,116,67,98,152,89,171,67,53,51,116,67,254,255,171,67,156,25,118,67,203,12,172,67,53,51,118,67,98,101,102,172,67,207,76,119,67,254,191,172,67,2,128,120,67,152,25,173,67,53,179,121,67,98,203,204,
                173,67,155,25,124,67,101,102,174,67,2,128,126,67,50,243,174,67,206,140,128,67,98,255,255,174,67,104,166,128,67,204,12,175,67,1,192,128,67,152,25,175,67,155,217,128,67,98,101,38,175,67,53,243,128,67,101,38,175,67,206,12,129,67,50,51,175,67,53,51,129,67,
                98,50,115,175,67,155,217,129,67,101,166,175,67,207,140,130,67,204,204,175,67,53,51,131,67,98,50,51,176,67,155,153,132,67,50,115,176,67,104,230,133,67,50,179,176,67,155,89,135,67,98,255,191,176,67,104,166,135,67,255,191,176,67,206,204,135,67,255,191,176,
                67,1,0,136,67,98,153,217,176,67,1,0,137,67,153,217,176,67,52,243,137,67,153,217,176,67,103,230,138,67,98,153,217,176,67,154,153,139,67,204,204,176,67,154,89,140,67,204,204,176,67,205,12,141,67,98,204,204,176,67,0,64,141,67,102,166,176,67,0,128,142,67,
                50,179,176,67,0,128,142,67,98,255,127,176,67,102,166,143,67,255,63,176,67,205,204,144,67,255,255,175,67,102,230,145,67,98,153,217,175,67,153,153,146,67,153,153,175,67,204,76,147,67,101,102,175,67,102,230,147,67,98,152,89,175,67,204,12,148,67,50,243,174,
                67,153,25,149,67,50,243,174,67,0,64,149,67,98,101,102,174,67,205,140,150,67,204,204,173,67,51,179,151,67,152,25,173,67,102,230,152,67,98,254,191,172,67,0,128,153,67,101,102,172,67,153,25,154,67,203,12,172,67,102,166,154,67,98,254,255,171,67,51,179,154,
                67,49,243,171,67,204,204,154,67,101,230,171,67,153,217,154,67,98,152,217,171,67,51,243,154,67,255,191,171,67,204,12,155,67,101,166,171,67,51,51,155,67,98,152,217,170,67,205,76,156,67,50,243,169,67,205,76,157,67,255,255,168,67,205,76,158,67,98,204,140,
                168,67,205,204,158,67,204,12,168,67,205,76,159,67,204,140,167,67,51,179,159,67,98,50,115,167,67,205,204,159,67,102,166,166,67,0,128,160,67,204,140,166,67,153,153,160,67,98,50,115,165,67,51,115,161,67,204,76,164,67,102,38,162,67,102,38,163,67,102,230,
                162,67,98,204,140,162,67,0,64,163,67,51,243,161,67,204,140,163,67,102,102,161,67,102,230,163,67,98,51,51,161,67,0,0,164,67,204,12,161,67,204,12,164,67,51,243,160,67,153,25,164,67,98,102,230,160,67,102,38,164,67,205,204,160,67,102,38,164,67,51,179,160,
                67,51,51,164,67,98,51,115,159,67,0,192,164,67,102,38,158,67,51,51,165,67,153,217,156,67,153,153,165,67,98,204,140,155,67,255,255,165,67,255,63,154,67,255,63,166,67,51,243,152,67,255,127,166,67,98,153,89,153,67,50,115,166,67,51,115,153,67,101,102,166,
                67,102,102,153,67,101,102,166,67,98,0,64,153,67,101,102,166,67,153,25,152,67,203,140,166,67,0,0,152,67,203,140,166,67,98,205,12,151,67,101,166,166,67,154,25,150,67,101,166,166,67,102,38,149,67,101,166,166,67,98,204,12,149,67,101,166,166,67,0,0,149,67,
                101,166,166,67,102,230,148,67,101,166,166,67,98,102,166,147,67,101,166,166,67,51,115,146,67,203,140,166,67,51,51,145,67,50,115,166,67,98,153,89,145,67,50,115,166,67,51,115,145,67,50,115,166,67,51,115,145,67,50,115,166,67,98,153,153,145,67,50,115,166,
                67,51,51,144,67,255,63,166,67,153,25,144,67,255,63,166,67,98,102,102,143,67,101,38,166,67,255,191,142,67,101,230,165,67,204,12,142,67,255,191,165,67,98,255,191,140,67,101,102,165,67,50,115,139,67,101,230,164,67,102,38,138,67,101,102,164,67,98,204,12,
                138,67,152,89,164,67,153,25,137,67,101,230,163,67,51,243,136,67,152,217,163,67,98,205,76,136,67,254,127,163,67,51,179,135,67,50,51,163,67,153,25,135,67,203,204,162,67,98,51,243,133,67,101,38,162,67,153,217,132,67,152,89,161,67,255,191,131,67,254,127,
                160,67,98,153,153,131,67,100,102,160,67,50,115,131,67,203,76,160,67,153,89,131,67,49,51,160,67,98,204,76,131,67,100,38,160,67,255,63,131,67,151,25,160,67,102,38,131,67,203,12,160,67,98,102,166,130,67,152,153,159,67,102,38,130,67,152,25,159,67,51,179,
                129,67,101,166,158,67,98,0,192,128,67,50,179,157,67,51,179,127,67,50,179,156,67,0,0,126,67,152,153,155,67,98,205,204,125,67,254,127,155,67,154,153,124,67,152,153,154,67,102,102,124,67,254,127,154,67,98,153,153,123,67,100,230,153,67,102,230,122,67,152,
                89,153,67,51,51,122,67,254,191,152,67,98,205,204,120,67,203,140,151,67,153,153,119,67,152,89,150,67,0,128,118,67,203,12,149,67,98,102,102,118,67,49,243,148,67,205,76,118,67,152,217,148,67,51,51,118,67,254,191,148,67,98,153,25,118,67,100,166,148,67,153,
                25,118,67,203,140,148,67,0,0,118,67,100,102,148,67,98,0,128,117,67,254,191,147,67,154,25,117,67,202,12,147,67,205,204,116,67,100,102,146,67,98,0,0,116,67,254,255,144,67,0,128,115,67,49,179,143,67,0,0,115,67,254,63,142,67,98,102,230,114,67,49,243,141,
                67,102,230,114,67,203,204,141,67,102,230,114,67,152,153,141,67,98,51,179,114,67,152,153,140,67,51,179,114,67,101,166,139,67,51,179,114,67,50,179,138,67,98,51,179,114,67,255,255,137,67,205,204,114,67,255,63,137,67,205,204,114,67,204,140,136,67,98,205,
                204,114,67,153,89,136,67,154,25,115,67,153,25,135,67,0,0,115,67,153,25,135,67,98,102,102,115,67,51,243,133,67,102,230,115,67,204,204,132,67,102,102,116,67,51,179,131,67,98,51,179,116,67,0,0,131,67,51,51,117,67,205,76,130,67,153,153,117,67,51,179,129,
                67,98,51,179,117,67,205,140,129,67,255,127,118,67,0,128,128,67,255,127,118,67,153,89,128,67,98,153,153,119,67,152,25,126,67,204,204,120,67,204,204,123,67,50,51,122,67,101,102,121,67,98,101,230,122,67,50,51,120,67,152,153,123,67,152,25,119,67,204,76,124,
                67,101,230,117,67,98,102,102,124,67,50,179,117,67,255,127,124,67,152,153,117,67,153,153,124,67,203,76,117,67,98,51,179,124,67,49,51,117,67,102,230,124,67,254,255,116,67,153,25,125,67,152,153,116,67,98,51,179,126,67,101,102,114,67,0,64,128,67,101,102,
                112,67,51,51,129,67,254,127,110,67,98,102,166,129,67,254,127,109,67,102,38,130,67,254,127,108,67,102,166,130,67,49,179,107,67,98,0,192,130,67,254,127,107,67,204,140,131,67,151,25,106,67,102,166,131,67,100,230,105,67,98,0,192,132,67,49,51,104,67,102,230,
                133,67,202,204,102,67,204,12,135,67,202,76,101,67,98,102,166,135,67,151,153,100,67,255,63,136,67,253,255,99,67,204,204,136,67,202,76,99,67,98,50,243,136,67,151,25,99,67,153,25,137,67,253,255,98,67,50,51,137,67,100,230,98,67,98,204,76,137,67,202,204,98,
                67,152,89,137,67,202,204,98,67,50,115,137,67,49,179,98,67,98,50,179,138,67,151,153,97,67,255,255,139,67,49,179,96,67,204,76,141,67,100,230,95,67,98,153,153,142,67,151,25,95,67,102,230,143,67,151,153,94,67,50,51,145,67,151,25,94,67,98,152,217,144,67,49,
                51,94,67,255,191,144,67,202,76,94,67,255,191,144,67,202,76,94,67,98,153,217,144,67,202,76,94,67,101,166,145,67,151,25,94,67,255,255,145,67,253,255,93,67,108,255,255,145,67,99,102,123,67,108,204,12,152,67,99,102,123,67,108,204,12,152,67,48,51,94,67,108,
                102,38,152,67,154,25,94,67,108,102,38,152,67,154,25,94,67,99,101,0,0 };
            
            
            Path svgPath;
            svgPath.loadPathFromData (pathData, sizeof (pathData));
            
            // Fit svgpath to inner dimensions of outlineArc
            svgPath.scaleToFit(-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f, true);
            
            p.addEllipse(-innerRadius, -innerRadius, innerRadius * 2.0f, innerRadius * 2.0f);
            g.fillPath (svgPath, AffineTransform::rotation (angle).translated (centreX, centreY));
    }
        
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderOutlineColourId));
        else
            g.setColour (Colour (0x80808080));
        
        
        Path outlineArc;
        outlineArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, thickness);
        
        outlineArc.closeSubPath();
        
        g.strokePath (outlineArc, PathStrokeType (slider.isEnabled() ? (isMouseOver ? 2.0f : 1.2f) : 0.3f));
    }
    
    else
    {
        if (slider.isEnabled())
            g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha
                        (isMouseOver ? 1.0f : 0.7f));
        else
            g.setColour (Colour (0x80808080));
        
        Path p;
        
        g.fillPath (p, AffineTransform::rotation (angle).translated (centreX, centreY));
    }
}


//===============================================================================
void CustomLookAndFeel::drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height,
                                float sliderPos, float minSliderPos, float maxSliderPos,
                                const Slider::SliderStyle style, Slider& slider) 
    {
        const auto sliderRadius = static_cast<float>(getSliderThumbRadius(slider));

	    auto isDownOrDragging = slider.isEnabled() && (slider.isMouseOverOrDragging() || slider.isMouseButtonDown());
	    auto knobColour (slider.findColour (Slider::thumbColourId).withMultipliedSaturation ((slider.hasKeyboardFocus (false) || isDownOrDragging) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (slider.isEnabled() ? 1.0f : 0.7f));
        g.setColour (knobColour);

        if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
        {
            float kx, ky;

            if (style == Slider::LinearVertical)
            {
                kx = x + width * 0.5f;
                ky = sliderPos;
                g.fillRect (Rectangle<float> (kx - sliderRadius, ky - 2.5f, sliderRadius * 2.0f, 5.0f));
            }
            else
            {
                kx = sliderPos;
                ky = y + height * 0.5f;
                g.fillRect (Rectangle<float> (kx - 2.5f, ky - sliderRadius, 5.0f, sliderRadius * 2.0f));
            }
        }
        else
        {
            // Just call the base class for the demo
            LookAndFeel_V2::drawLinearSliderThumb (g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        }
    }

//===============================================================================
 void CustomLookAndFeel::drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
                               bool isMouseOverButton, bool isButtonDown) 
    {
        auto baseColour (backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                           .withMultipliedAlpha (button.isEnabled() ? 0.9f : 0.5f));

        if (isButtonDown || isMouseOverButton)
            baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);

        const auto flatOnLeft   = button.isConnectedOnLeft();
        const auto flatOnRight  = button.isConnectedOnRight();
        const auto flatOnTop    = button.isConnectedOnTop();
        const auto flatOnBottom = button.isConnectedOnBottom();

        const auto width  = button.getWidth() - 1.0f;
        const auto height = button.getHeight() - 1.0f;

        if (width > 0 && height > 0)
        {
            const auto cornerSize = jmin (10.0f, jmin (width, height) * 0.55f);
            const auto lineThickness = cornerSize * 0.1f;
            const auto halfThickness = lineThickness * 0.5f;

            Path outline;
            outline.addRoundedRectangle (0.5f + halfThickness, 0.5f + halfThickness, width - lineThickness, height - lineThickness,
                                         cornerSize, cornerSize,
                                         ! (flatOnLeft  || flatOnTop),
                                         ! (flatOnRight || flatOnTop),
                                         ! (flatOnLeft  || flatOnBottom),
                                         ! (flatOnRight || flatOnBottom));

            const Colour outlineColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId
                                                                                   : TextButton::textColourOffId));

            g.setColour (baseColour);
            g.fillPath (outline);

            if (! button.getToggleState())
            {
                g.setColour (outlineColour);
                g.strokePath (outline, PathStrokeType (lineThickness));
            }
        }
    }

//===============================================================================
 void CustomLookAndFeel::drawTickBox(Graphics& g, Component& component,
	 float x, float y, float w, float h,
	 bool ticked,
	 bool isEnabled,
	 bool isMouseOverButton,
	 bool isButtonDown)
 {
	 const float diameter = w * 0.7f;
	 const float outlineThickness = 1.0f;
	 y = y + (h - diameter) * 0.5f;

	 bool isDownOrDragging = component.isEnabled() && (component.isMouseOverOrDragging() || component.isMouseButtonDown());

	 const Colour outlineColour(component.findColour(TextButton::buttonColourId).withMultipliedSaturation((component.hasKeyboardFocus(false) || isDownOrDragging) ? 1.3f : 0.9f)
		 .withMultipliedAlpha(component.isEnabled() ? 1.0f : 0.7f));

	 const Rectangle<float> a (x, y, diameter, diameter);
     const float halfThickness = outlineThickness * 0.5f;

	 Path p;
	 p.addEllipse (x + halfThickness, y + halfThickness, diameter - outlineThickness, diameter - outlineThickness);

	 const DropShadow ds (Colours::black, 1, Point<int> (0, 0));
	 ds.drawForPath (g, p);

	 if (ticked)
	 {
		 //g.setColour(isEnabled ? findColour(TextButton::buttonOnColourId) : Colours::grey);
		 g.setColour(findColour(TextButton::buttonOnColourId));
		 g.fillPath(p);
	 }
	 else
	 {
		g.setColour (outlineColour);
		g.fillPath (p);
	 }

	 g.setColour (outlineColour.brighter());
	 g.strokePath (p, PathStrokeType (outlineThickness));
	
 }
    
//===============================================================================
