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
#ifndef NPF_H
#define NPF_H

#include <QNetworkProxyFactory>
#include <QUrl>
#include <QStringList>
#include <QSettings>

class NPF : public QNetworkProxyFactory
{
public:
	enum ProxyPreference { SystemProxy, NoProxy, DefinedProxy };

    explicit NPF();
    void loadSettings(QNetworkProxy::ProxyType networkProxyType,QString proxyHost,quint16 proxyPort,QString proxyUser,QString proxyPass);

    QList<QNetworkProxy> queryProxy(const QNetworkProxyQuery &query = QNetworkProxyQuery());
    void gogogo();
private:
    ProxyPreference m_proxyPreference;
    QNetworkProxy::ProxyType m_proxyType;
    QString m_hostName;
    quint16 m_port;
    QString m_username;
    QString m_password;
    QStringList m_proxyExceptions;
};

#endif // NPF_H

