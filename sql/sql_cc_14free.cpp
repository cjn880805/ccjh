/*
2001-07-02 数据库修正:
在查询数据库功能完成后,
所有的返回之前请执行一次 mysql_free_result(result);
用于释放查询结果
大概其他版本里也有未照顾到的地方.需要修正
*/
#include "stdafx.h"

#include "../server/Globle.h"
#include "../server/User.h"
#include "../combat/Combatd.h"
#include "../server/Channel.h"

#include "sql.h"

char * check_legal_name(const char * name);
 
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

MYSQL mysql;
MYSQL chargesql;		//计费查询

double		g_game_count;		//游戏每分种消耗的点数

//恢复数据
BOOL  Restore_Data()
{
	char msg[255];	
	MYSQL_RES *result = NULL;
		
	snprintf(msg, 255, "select cc_id from ccjhdb where cc_server =%d", sys_server_id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("Restore_Data:query db fail!");
		return FALSE;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("Restore_Data:database fail: store null");
		return FALSE;
	}

	int n = mysql_num_rows(result);
	MYSQL_ROW row;

	output_error("restore users:%ld", n);

	for(int i=0; i < n; i++)
	{
		row = mysql_fetch_row(result);
		if(row == NULL || row[0] == NULL)
		{
			output_error("Restore_Data:database fail:row is NULL %ld.", i);
			continue;
		}
		
		//账号
		CUser * me = add_user();
		me->set("id", row[0]);
		
		output_error("restore user (%s) data!", row[0]);

		if(! me->Load())		
		{
			output_error("restore user (%s) data fail!", row[0]);
		}
		else
		{
			me->SaveToServer();
			me->set_temp("online", sys_server_id);
		}

		destruct(me);
	}

	mysql_free_result(result);
/*
	//清空本服务器的数据库
	char msg[255];
	snprintf(msg, 255, "update ccjhdb set cc_server = 0 where cc_server= %d", sys_server_id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		fprintf(stderr, "clear online message:query db fail!");
		return FALSE;
	}
*/
	//清空临时目录下的数据。
	for(int i=1; i<26; i++)
	{
		system(snprintf(msg, 255, "rm -rf data/user/%ld/*.*", i) );
		system(snprintf(msg, 255, "rm -rf data/saveobj/%ld/*.*", i) );
	}

	return TRUE;
}

BOOL InitSQLServer(const char * ipaddress, const char * name, const char * password)
{	
	
	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, ipaddress, name, password, NULL, 0, NULL, 0))
	{
		fprintf(stderr, "InitSQLServer -- Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
		return FALSE;
	}

	if(mysql_select_db(&mysql, "mud") != 0)
	{
		fprintf(stderr, "InitSQLServer -- Failed to select database: %s\n",
			mysql_error(&mysql));
		return FALSE;
	}

	return Restore_Data();
}

/*
//load old user data to database
int LoadDataBase()
{
	char fname[512], passwd[40];
	FILE * fp;

	for(int userid=1; userid <= g_CurrentAccount; userid++)
	{
		//1 read passwd
		snprintf(fname, 80, "data/login/%d.lgn", userid);
		if(! (fp = fopen(fname, "rb")) ) return 0;
	
		fread(passwd, 40, 1, fp);
		fclose(fp);	

		//2 clear table
		
		
		//3 insert data to database
		snprintf(fname, 512, "insert into ccjhdb set cc_name = 'noname', cc_passwd = '%s', cc_email = 'lanwood@263.net', cc_gender = 'nnnn'",	passwd);
	
		//根据需要变化
		int nTmp = mysql_real_query(&mysql, fname, strlen(fname));
		if(nTmp != 0)
		{
			fprintf(stderr, "Database Error: %s\n", mysql_error(&mysql));
		}

		//4. update data
		CUser me;

		snprintf(fname, 40, "%d", userid);
		me.set("id", fname);

		me.OldLoad();
		me.Save();		
	}

	return 1;
}
*///zysm2001

bool check_c_in_str(char *str, long size, char c)
{
	for (int i=0; i<size; i++)
	{
		if (str[i] == c)
		{
			return true;
		}
	}
	return false;
}

BOOL VerifyUser(const char * userid, char * passwd)
{
	MYSQL_RES *result = NULL;
	char szQuery[512];
	int nResult = 0;

	//检查卡号和密码是否正确
	long size = strlen(passwd);
	if(check_c_in_str(passwd, size, '\'') || check_c_in_str(passwd, size, '|') || check_c_in_str(passwd, size, '=') )
	{
		notify_fail("你的卡号密码中包含非法字符,服务器拒绝登陆。请和109巫师联系，由他为你解决。");
		return FALSE;
	}

	snprintf(szQuery, 512, "select * from ccjhdb where cc_id=%s and cc_passwd='%s'", userid, passwd);
	nResult = mysql_real_query(&mysql, szQuery, strlen(szQuery));
	if( nResult != 0)
	{
		output_error("user:%ld passwd:%s query db fail!", userid, passwd);
		return FALSE;
	}
	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("database fail: user:%ld passwd:%s store null", userid, passwd);
		return FALSE;
	}
	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return FALSE;		
	}
	//paswd pass OK!

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL)
	{
		mysql_free_result(result);
		return FALSE;
	}

//	char szTmp[8192];
//	snprintf(szTmp, 8192, "%s", row[17]);

	if(atoi(row[9]) > 15)
	{
		mysql_free_result(result);
		return FALSE;
	}
	
	if(row[17] == NULL || row[17][0] == 0 )//是新人
	{
		char msg[40];
		CUser me;
		//从新读出属性数据，开始分配
		me.set_name(snprintf( msg, 40, "%s",row[1]), userid);
		me.set("gender", snprintf( msg, 40, "%s",row[10]));
		me.set("str", atoi(row[4]));
		me.set("int", atoi(row[5]));
		me.set("con", atoi(row[6]));
		me.set("dex", atoi(row[7]));	

		//判断四属性值是否合法
		int nStr = me.query("str");
		int nCon = me.query("con");
		int nInt = me.query("int");
		int nDex = me.query("dex");

		if(nStr < 10 || nStr > 30)
		{
			mysql_free_result(result);
			notify_fail("力量值非法。");
			return FALSE;
		}

		if(nCon < 10 || nCon > 30)
		{
			mysql_free_result(result);
			notify_fail("体质值非法。");
			return FALSE;
		}

		if(nInt < 10 || nInt > 30)
		{
			mysql_free_result(result);
			notify_fail("智慧值非法。");
			return FALSE;
		}

		if(nDex < 10 || nDex > 30)
		{
			mysql_free_result(result);
			notify_fail("敏捷值非法。");
			return FALSE;
		}

		if(nStr + nCon + nInt + nDex > 84)
		{
			mysql_free_result(result);
			notify_fail("天赋属性值总和不得超过84。");
			return FALSE;
		}
			
		setup_char(&me);	
		me.set("title", "普通百姓");

		me.set("birthday", current_time);
		//me.set("combat_exp", 0);
		//me.set("level", 1);

		CVector v;
		v.append("chat");
		v.append("rumor");

		me.set("channels", v);
		me.set("start_city", START_ROOM);
					
		mysql_free_result(result);


		//现在检查是否合法
		if(strlen(me.name(1)) < 2 || strlen(me.name(1)) > 14)
		{
			notify_fail("姓名长度非法。");
			return FALSE;
		}

		strcpy(msg, check_legal_name(me.name(1)));
		if(msg[0])
		{
			notify_fail(msg);
			return FALSE;
		}

		me.SaveToServer();
	}
	else
	{
		mysql_free_result(result);
	}
	
	return TRUE;
}

void DisconnectSQLServer()
{
	mysql_close(&mysql);	
}


///////////////////////////////计费系统模块/////////////////////////////////////
//初始化计费数据库
BOOL InitChargeServer(const char * ipaddress, const char * name, const char * password)
{	
	mysql_init(&chargesql);
	
	///////////////Read ChargeFile/////////
/*	FILE *pFile;
	pFile=fopen("data/charge.ini","r");
	if(pFile == NULL)
	{
		printf("\n Read charge.ini error!\n");
		return FALSE;
	}
	char tmp[3][50];
	
	for(int i=0;i<3;i++)
	{
		//fseek(pFile,nStr,SEEK_SET);
		fscanf(pFile,tmp[i]);
	//	nStr+=(strlen(tmp[i])+1);
	}
	fclose(pFile);
	*/
//	if(!mysql_real_connect(&chargesql,tmp[0],tmp[1],tmp[2],NULL,0,NULL,0))
	if(!mysql_real_connect(&chargesql,"202.105.55.125","gkgzsql","wsadb82b41",NULL,0,NULL,0))
	{
		fprintf(stderr, "InitChargeServer -- Failed to connect to database: Error: %s\n",
			mysql_error(&chargesql));
		return FALSE;
	}

	if(mysql_select_db(&chargesql, "charge") != 0)
	{
		fprintf(stderr, "InitChargeServer -- Failed to select database: %s\n",
			mysql_error(&chargesql));
		return FALSE;
	}

	g_game_count = Game_Count();	//获得游戏每分种消耗的点数

	return TRUE;
}

//关闭计费数据库
void DisconnectChargeServer()
{
	mysql_close(&chargesql);	
}

//用户输入卡号,密码,比较是否有效和是否还有点数.
//成功返回剩余点数,否则返回0
double Verify_Card(const char * id, const char * cardno, const char * password, int & month)
{
	MYSQL_RES *result = NULL;
	char szQuery[255];
	int nResult = 0;

	//检查卡号和密码是否正确
	long size = strlen(password);
			
	if(check_c_in_str((char *)password, size, '\'') || check_c_in_str((char *)password, size, '|') || check_c_in_str((char *)password, size, '=') )
	{
		notify_fail("你的密码中包含非法字符,服务器拒绝登陆。请和109巫师联系，由他为你解决。");
		return FALSE;
	}
	snprintf(szQuery, 255, "select value, valiade, maxvalue, endtime, online from Card where cardno = '%s' and password = '%s'", cardno, password);
	nResult = mysql_real_query(&chargesql, szQuery, strlen(szQuery));
	if( nResult != 0)
	{		
		output_error("%s query db fail:%s!", szQuery, mysql_error(&chargesql));
		return 0;
	}
	result = mysql_store_result(&chargesql);
	if(result == NULL)
	{		
		output_error("database fail: cardno:%s password:%s store null", cardno, password);
		return 0;
	}
	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return notify_fail("非可用卡号。");		
	}
	//passwd pass OK!

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL)
	{
		mysql_free_result(result);
		return notify_fail("该卡不可用！");
	}

	//now row[0] = value row[1] = valiade
	if(! atol(row[1]))		//该卡不可用
	{
		mysql_free_result(result);
		return notify_fail("该卡不可用。");
	}

	//以下为月卡增加代码
	double value = atof(row[0]);
	int ret = atoi(row[2]);
	time_t endtime = (time_t)atol(row[3]);
	int online = atol(row[4]);
		
	mysql_free_result(result);

	if(! ret)	//是否月卡
	{
		month = 1;
		value = 2592000;		//30天
		
		time_t t;
		time(&t);
			
		if(! endtime)	//空卡 初始化
		{
			struct tm * newtime;
			newtime = localtime( &t );
			char begintime[64];

			sprintf(begintime, "%d/%02d/%02d %02d:%02d:%02d",
				1900 + newtime->tm_year, newtime->tm_mon + 1, newtime->tm_mday, 
				newtime->tm_hour, newtime->tm_min, newtime->tm_sec);

			t += (time_t)value;
			snprintf(szQuery, 255, "update Card set begintime = '%s', endtime = %ld, online = %s where cardno = '%s'", begintime, t, id, cardno);
			nResult = mysql_real_query(&chargesql, szQuery, strlen(szQuery));

			if( nResult != 0)
			{
				output_error("Verify_Card:%s!", mysql_error(&chargesql));
				return notify_fail("卡初始化错误。");
			}
		}
		else
		{
			if(t > endtime)	return notify_fail("该卡到期。");
			if(online && online != atol(id)) return notify_fail("用户(%ld)使用中。", online);

			value = endtime - t;

			//写入在线记录
			snprintf(szQuery, 255, "update Card set online = %s where cardno = '%s'", id, cardno);
			nResult = mysql_real_query(&chargesql, szQuery, strlen(szQuery));

			if( nResult != 0)
			{
				output_error("Verify_Card:%s!", mysql_error(&chargesql));
				return notify_fail("卡写入标志错误。");
			}
		}		

		value /= 10;
	}

	return value;
}

//修改用户剩余点数
double Charge_Card(CChar * me, const char * cardno, double resume)
{
	char msg[255];
	MYSQL_RES *result = NULL;
	int nResult = 0;

	//检查卡号和密码是否正确
	snprintf(msg, 255, "select value from Card where cardno = '%s'", cardno);
	nResult = mysql_real_query(&chargesql, msg, strlen(msg));
	if( nResult != 0)
	{		
		output_error("%s query db fail:%s!", msg, mysql_error(&chargesql));
		return 0;
	}

	result = mysql_store_result(&chargesql);
	if(result == NULL)
	{		
		output_error("database fail: cardno:%s restore null", cardno);
		return 0;
	}

	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return 0;		
	}
	
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL)
	{
		mysql_free_result(result);
		return 0;
	}

	//now row[0] = value	
	double value = atof(row[0]);

	if(resume > value) resume = value;
		
	mysql_free_result(result);
	
	double left = value - resume + 0.05;
	if(left < 0.1) left = 0;
	
	sprintf(msg, "update Card set value = %.1f where cardno = '%s'", left, cardno);
	
	nResult = mysql_real_query(&chargesql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("Charge_Card:%s!", mysql_error(&chargesql));
		return 0;
	}

	sprintf(msg, "用户%s(%s)卡(%s)计费%.1f点.余额%.1f.", me->name(1), me->id(1), cardno, resume, left);
	output_error(msg);

	return resume;
}

//清除月卡在线标记
void clear_online(CChar * me, const char * cardno, LONG resume)
{
	char msg[255];
	int nResult = 0;

	sprintf(msg, "update Card set online = 0 where cardno = '%s'", cardno);
	
	nResult = mysql_real_query(&chargesql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("clear_online:%s!", mysql_error(&chargesql));
		return;
	}

	sprintf(msg, "用户%s(%s)月卡(%s)在线时间:%ld秒", me->name(1), me->id(1), cardno, resume);
	output_error(msg);
}

//返回本游戏每分钟消耗的点数
double Game_Count()
{
	MYSQL_RES *result = NULL;
	char msg[255];
	int nResult = 0;

	//检查卡号和密码是否正确
	snprintf(msg, 255, "select game_count from Game_count where name = 'CCJH'");
	nResult = mysql_real_query(&chargesql, msg, strlen(msg));
	if( nResult != 0)
	{		
		output_error("Game_Count:%s!", mysql_error(&chargesql));
		return 0;
	}

	result = mysql_store_result(&chargesql);
	if(result == NULL)
	{		
		output_error("Game_Count:  store null");
		return 0;
	}

	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return 0;		
	}
	//passwd pass OK!

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL)
	{
		mysql_free_result(result);
		return 0;
	}

	//now row[0] = game_count
	double count = atof(row[0]);
	mysql_free_result(result);

	return count;
}

//查询Game_count表
int Query_Game_Count_Table(double &day_count, double &month_count, double &count)
{
	MYSQL_RES *result = NULL;
	char msg[255];
	int nResult = 0;

	//检查卡号和密码是否正确
	snprintf(msg, 255, "select day_count, month_count, count from Game_count where name = 'CCJH'");
	nResult = mysql_real_query(&chargesql, msg, strlen(msg));
	if( nResult != 0)
	{		
		output_error("Game_Count:%s!", mysql_error(&chargesql));
		return 0;
	}

	result = mysql_store_result(&chargesql);
	if(result == NULL)
	{		
		output_error("Game_Count:  store null");
		return 0;
	}

	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return 0;		
	}
	
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL)
	{
		mysql_free_result(result);
		return 0;
	}

	//now row[0] = day_count, row[1] = month_count
	day_count = atof(row[0]);
	month_count = atof(row[1]);
	count = atof(row[2]);

	mysql_free_result(result);

	return 1;
}

//修改Game_count表
BOOL Modify_Game_Count_Table(double day_count, double month_count, double count)
{
	char msg[255];
	sprintf(msg, "update Game_count set day_count = %.1f, month_count = %.1f, count = %.1f where name = 'CCJH'", day_count, month_count, count);
	int nResult = mysql_real_query(&chargesql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("Modify_Game_count_Table:%s!", mysql_error(&chargesql));
		return FALSE;
	}
	return TRUE;
}

///////////////////////////////////////////////////////////////////////////////
//游戏中呼叫的部分 CCJH专用
double Valid_Enter_Game(CUser * me, const char * cardno, const char * password)
{
	int month = 0;

	//不收费
	if(! cardno[0] && ! sys_server_charge)
	{
		me->set_temp("charge/free", 1);		//免费用户
		return 1;
	}

	//15岁玩家免费
	if(me->query("mud_age") < 172800)
	{
		me->set_temp("charge/free", 1);		//免费用户
		return 1;
	}

	//巫师免费
	if(wizardp(me))
	{
		me->set_temp("charge/free", 1);		//免费用户
		return 1;
	}
	
	//免费IP
	if(g_Channel.filter_ip(me->querystr_temp("client/ip_address")))
	{
		me->set_temp("charge/free", 1);		//免费用户
		return 1;
	}

	notify_fail("卡已过期。");
	double value = Verify_Card(me->id(1), cardno, password, month);

	if(! value) return 0;
	
	me->set_temp("charge/login", current_time);		//开始计费时间
	me->set_temp("charge/card", cardno);
	me->set_temp("charge/free", 0l);				//收费用户
	me->set_temp("charge/month", month);			//是否月卡
	
	return value;
}

//用户离线时呼叫,计算使用时间
void OnUserOut(CUser * me)
{
	if(me->query_temp("charge/free"))		//免费用户
		return;

	LONG game_time = (current_time - me->query_temp("charge/login")) / 60;

	if(me->query_temp("charge/month"))		//月卡用户
	{
		clear_online(me, me->querystr_temp("charge/card"), game_time);
		return;
	}

	if(game_time <= 0) return;

	double charge = game_time * g_game_count / 3.0;	//扣除点数

	charge = Charge_Card(me, me->querystr_temp("charge/card"), charge);
	if(! charge) return;
	
	//清空
	me->set_temp("charge/login", current_time);

	//累加到统计表
	double month_count, day_count, count;
	if(!Query_Game_Count_Table(day_count, month_count, count))
		return;
	
	day_count += charge;
	month_count += charge;
	count += charge;

	Modify_Game_Count_Table(day_count, month_count, count);
}

//-------------------------------------------------------------------------
//获得排行榜 由外部物件呼叫
int paihangbang(CContainer * me)
{
	char msg[255];	
	MYSQL_RES *result = NULL;
		
	snprintf(msg, 255, "select cc_id, cc_name, cc_family, cc_experice "
						"from ccjhdb "
						"where cc_experice > 300000 and cc_freeze = 0 and cc_grant = 30 "
						"order by cc_experice desc "
						"LIMIT 0, 1000");

	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("paihangbang:query db fail!");
		return 0;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("paihangbang:database fail: store null");
		return 0;
	}

	int n = mysql_num_rows(result);
	MYSQL_ROW row;

	for(int i=0; i < n; i++)
	{
		row = mysql_fetch_row(result);
		if(row == NULL || row[0] == NULL)
		{
			output_error("paihangbang:database fail:row is NULL %ld.", i);
			continue;
		}
				
		char name[40], fam[20];
		strncpy(name, row[1], 40);
		strncpy(fam, row[2], 20);
		me->handle_action("update", NULL, snprintf(msg, 255, "%ld %s %s %s %s", 
			i, row[0], name[0] ? name : "无名氏", fam[0] ? fam : "无门派", row[3]));
	}

	mysql_free_result(result);
	return 1;
}



