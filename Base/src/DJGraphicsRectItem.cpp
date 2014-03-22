//****************************************************************************
//Copyright (C) 2005-2006 Beijing BlueDJ Technology Co.,Ltd. All rights reserved.

//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either version 2
//of the License, or (at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with this program (in the file LICENSE.GPL); if not, write to the Free Software
//Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

//Please visit http://www.bluedj.com for more infomation about us.
//Contact us at ggwizard@gmail.com or darkdong@gmail.com.
//****************************************************************************/

#include "DJGraphicsRectItem.h"
#include "Utility.h"

static int	countRectItem	= 0;

DJGraphicsRectItem::DJGraphicsRectItem( QGraphicsItem * parent, QGraphicsScene * scene )
	:QGraphicsRectItem( parent, scene )
{
	djDebug()<<"DJGraphicsRectItem constructor"<<countRectItem++;
}
DJGraphicsRectItem::~DJGraphicsRectItem()
{
	djDebug()<<"DJGraphicsRectItem destructor"<<countRectItem--;
}
int DJGraphicsRectItem::type() const
{
	return DJGraphicsRectItemType;
}
void DJGraphicsRectItem::setRect ( const QRectF & rectangle )
{
	m_rect	= rectangle;
}
void DJGraphicsRectItem::setRect( qreal x, qreal y, qreal width, qreal height )
{
	m_rect	= QRectF(x,y,width,height);
}
void DJGraphicsRectItem::adjustPos( const QMatrix& m )
{
	QRectF rect	= m.mapRect( m_rect );
	QGraphicsRectItem::setRect( rect );
}