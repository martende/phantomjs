/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2011  nowrep
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#include "networkproxyfactory.h"
#include <stdio.h>

NPF::NPF() :
    QNetworkProxyFactory()
{
	
}
void NPF::gogogo() {
	return;
}
void NPF::loadSettings(QNetworkProxy::ProxyType networkProxyType,QString proxyHost,quint16 proxyPort,QString proxyUser,QString proxyPass)
{
	m_proxyType=networkProxyType;
	m_hostName = proxyHost;
	m_port=proxyPort;
	m_proxyExceptions << "localhost" << "127.0.0.1";
	m_username = proxyUser;
	m_password = proxyPass; 
	/*
    QSettings settings(mApp->getActiveProfil()+"settings.ini", QSettings::IniFormat);
    settings.beginGroup("Web-Proxy");
    m_proxyPreference = ProxyPreference(settings.value("UseProxy", SystemProxy).toInt());
    m_proxyType = QNetworkProxy::ProxyType(settings.value("ProxyType", QNetworkProxy::HttpProxy).toInt());
    m_hostName = settings.value("HostName", "").toString();
    m_port = settings.value("Port", 8080).toInt();
    m_username = settings.value("Username", "").toString();
    m_password = settings.value("Password", "").toString();
    m_proxyExceptions = settings.value("ProxyExceptions", QStringList() << "localhost" << "127.0.0.1").toStringList();
    settings.endGroup();
    */
}

QList<QNetworkProxy> NPF::queryProxy(const QNetworkProxyQuery &query)
{
    QNetworkProxy proxy;


    if (m_proxyExceptions.contains(query.url().host(), Qt::CaseInsensitive)) {
        proxy.setType(QNetworkProxy::NoProxy);
    } else {
    	proxy.setType(m_proxyType);
        proxy.setHostName(m_hostName);
        proxy.setPort(m_port);
        if (!m_username.isEmpty() && !m_password.isEmpty() ) {
        	proxy.setUser(m_username);
        	proxy.setPassword(m_password);
        }
    }

    return QList<QNetworkProxy>() << proxy;
}

