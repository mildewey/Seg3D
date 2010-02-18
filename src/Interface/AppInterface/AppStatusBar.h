/*
 For more information, please see: http://software.sci.utah.edu
 
 The MIT License
 
 Copyright (c) 2009 Scientific Computing and Imaging Institute,
 University of Utah.
 
 
 Permission is hereby granted, free of charge, to any person obtaining a
 copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */

#ifndef INTERFACE_APPINTERFACE_APPSTATUSBAR_H
#define INTERFACE_APPINTERFACE_APPSTATUSBAR_H

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif 

// Boost includes
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>

// QT includes
#include <QtGui>

// Application includes
#include <Utils/Core/Log.h>
#include <Interface/AppInterface/HistoryWidget.h>
//#include <Application/Action/ActionDispatcher.h>

namespace Seg3D {
	
class AppStatusBar : public QObject
{
		Q_OBJECT
		
		// -- constructor / destructor --    
	public:
		AppStatusBar(QMainWindow* parent = 0);
		virtual ~AppStatusBar();
		
		
	public Q_SLOTS:
		void set_coordinates_label( int y, int x, int z );
		void set_coordinates_mode( bool is_local_ );
		void set_status_report_label( std::string& report );
		void activate_history(bool is_active_);
		
		
		// -- build status bar widgets -- //    
	private:
		void build_coordinates_label();
		void build_status_report_label();
		void build_buttons();
		
		// -- status bar components -- //
	private:
		QLabel* coordinates_label_;
		QLabel* status_report_label_;
		QToolButton* world_button_;
		QToolButton* info_button_;
	
		HistoryWidget* history_widget_;
		int coordinates_mode_;
		QIcon world_icon_;
		QIcon text_icon_;
	
	private Q_SLOTS:
		void fix_icon_status();
	

		
	public:
		typedef QPointer<AppStatusBar> qpointer_type;
		
		static void UpdateStatusBar( qpointer_type statusbar, int message_type, std::string message );
	
		
		
		
		
};

} // end namespace Seg3D


#endif //INTERFACE_APPINTERFACE_APPSTATUSBAR_H


















