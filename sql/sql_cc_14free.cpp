/*
2001-07-02 ���ݿ�����:
�ڲ�ѯ���ݿ⹦����ɺ�,
���еķ���֮ǰ��ִ��һ�� mysql_free_result(result);
�����ͷŲ�ѯ���
��������汾��Ҳ��δ�չ˵��ĵط�.��Ҫ����
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
MYSQL chargesql;		//�ƷѲ�ѯ

double		g_game_count;		//��Ϸÿ�������ĵĵ���

//�ָ�����
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
		
		//�˺�
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
	//��ձ������������ݿ�
	char msg[255];
	snprintf(msg, 255, "update ccjhdb set cc_server = 0 where cc_server= %d", sys_server_id);
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		fprintf(stderr, "clear online message:query db fail!");
		return FALSE;
	}
*/
	//�����ʱĿ¼�µ����ݡ�
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
	
		//������Ҫ�仯
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

	//��鿨�ź������Ƿ���ȷ
	long size = strlen(passwd);
	if(check_c_in_str(passwd, size, '\'') || check_c_in_str(passwd, size, '|') || check_c_in_str(passwd, size, '=') )
	{
		notify_fail("��Ŀ��������а����Ƿ��ַ�,�������ܾ���½�����109��ʦ��ϵ������Ϊ������");
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
	
	if(row[17] == NULL || row[17][0] == 0 )//������
	{
		char msg[40];
		CUser me;
		//���¶����������ݣ���ʼ����
		me.set_name(snprintf( msg, 40, "%s",row[1]), userid);
		me.set("gender", snprintf( msg, 40, "%s",row[10]));
		me.set("str", atoi(row[4]));
		me.set("int", atoi(row[5]));
		me.set("con", atoi(row[6]));
		me.set("dex", atoi(row[7]));	

		//�ж�������ֵ�Ƿ�Ϸ�
		int nStr = me.query("str");
		int nCon = me.query("con");
		int nInt = me.query("int");
		int nDex = me.query("dex");

		if(nStr < 10 || nStr > 30)
		{
			mysql_free_result(result);
			notify_fail("����ֵ�Ƿ���");
			return FALSE;
		}

		if(nCon < 10 || nCon > 30)
		{
			mysql_free_result(result);
			notify_fail("����ֵ�Ƿ���");
			return FALSE;
		}

		if(nInt < 10 || nInt > 30)
		{
			mysql_free_result(result);
			notify_fail("�ǻ�ֵ�Ƿ���");
			return FALSE;
		}

		if(nDex < 10 || nDex > 30)
		{
			mysql_free_result(result);
			notify_fail("����ֵ�Ƿ���");
			return FALSE;
		}

		if(nStr + nCon + nInt + nDex > 84)
		{
			mysql_free_result(result);
			notify_fail("�츳����ֵ�ܺͲ��ó���84��");
			return FALSE;
		}
			
		setup_char(&me);	
		me.set("title", "��ͨ����");

		me.set("birthday", current_time);
		//me.set("combat_exp", 0);
		//me.set("level", 1);

		CVector v;
		v.append("chat");
		v.append("rumor");

		me.set("channels", v);
		me.set("start_city", START_ROOM);
					
		mysql_free_result(result);


		//���ڼ���Ƿ�Ϸ�
		if(strlen(me.name(1)) < 2 || strlen(me.name(1)) > 14)
		{
			notify_fail("�������ȷǷ���");
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


///////////////////////////////�Ʒ�ϵͳģ��/////////////////////////////////////
//��ʼ���Ʒ����ݿ�
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

	g_game_count = Game_Count();	//�����Ϸÿ�������ĵĵ���

	return TRUE;
}

//�رռƷ����ݿ�
void DisconnectChargeServer()
{
	mysql_close(&chargesql);	
}

//�û����뿨��,����,�Ƚ��Ƿ���Ч���Ƿ��е���.
//�ɹ�����ʣ�����,���򷵻�0
double Verify_Card(const char * id, const char * cardno, const char * password, int & month)
{
	MYSQL_RES *result = NULL;
	char szQuery[255];
	int nResult = 0;

	//��鿨�ź������Ƿ���ȷ
	long size = strlen(password);
			
	if(check_c_in_str((char *)password, size, '\'') || check_c_in_str((char *)password, size, '|') || check_c_in_str((char *)password, size, '=') )
	{
		notify_fail("��������а����Ƿ��ַ�,�������ܾ���½�����109��ʦ��ϵ������Ϊ������");
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
		return notify_fail("�ǿ��ÿ��š�");		
	}
	//passwd pass OK!

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL)
	{
		mysql_free_result(result);
		return notify_fail("�ÿ������ã�");
	}

	//now row[0] = value row[1] = valiade
	if(! atol(row[1]))		//�ÿ�������
	{
		mysql_free_result(result);
		return notify_fail("�ÿ������á�");
	}

	//����Ϊ�¿����Ӵ���
	double value = atof(row[0]);
	int ret = atoi(row[2]);
	time_t endtime = (time_t)atol(row[3]);
	int online = atol(row[4]);
		
	mysql_free_result(result);

	if(! ret)	//�Ƿ��¿�
	{
		month = 1;
		value = 2592000;		//30��
		
		time_t t;
		time(&t);
			
		if(! endtime)	//�տ� ��ʼ��
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
				return notify_fail("����ʼ������");
			}
		}
		else
		{
			if(t > endtime)	return notify_fail("�ÿ����ڡ�");
			if(online && online != atol(id)) return notify_fail("�û�(%ld)ʹ���С�", online);

			value = endtime - t;

			//д�����߼�¼
			snprintf(szQuery, 255, "update Card set online = %s where cardno = '%s'", id, cardno);
			nResult = mysql_real_query(&chargesql, szQuery, strlen(szQuery));

			if( nResult != 0)
			{
				output_error("Verify_Card:%s!", mysql_error(&chargesql));
				return notify_fail("��д���־����");
			}
		}		

		value /= 10;
	}

	return value;
}

//�޸��û�ʣ�����
double Charge_Card(CChar * me, const char * cardno, double resume)
{
	char msg[255];
	MYSQL_RES *result = NULL;
	int nResult = 0;

	//��鿨�ź������Ƿ���ȷ
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

	sprintf(msg, "�û�%s(%s)��(%s)�Ʒ�%.1f��.���%.1f.", me->name(1), me->id(1), cardno, resume, left);
	output_error(msg);

	return resume;
}

//����¿����߱��
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

	sprintf(msg, "�û�%s(%s)�¿�(%s)����ʱ��:%ld��", me->name(1), me->id(1), cardno, resume);
	output_error(msg);
}

//���ر���Ϸÿ�������ĵĵ���
double Game_Count()
{
	MYSQL_RES *result = NULL;
	char msg[255];
	int nResult = 0;

	//��鿨�ź������Ƿ���ȷ
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

//��ѯGame_count��
int Query_Game_Count_Table(double &day_count, double &month_count, double &count)
{
	MYSQL_RES *result = NULL;
	char msg[255];
	int nResult = 0;

	//��鿨�ź������Ƿ���ȷ
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

//�޸�Game_count��
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
//��Ϸ�к��еĲ��� CCJHר��
double Valid_Enter_Game(CUser * me, const char * cardno, const char * password)
{
	int month = 0;

	//���շ�
	if(! cardno[0] && ! sys_server_charge)
	{
		me->set_temp("charge/free", 1);		//����û�
		return 1;
	}

	//15��������
	if(me->query("mud_age") < 172800)
	{
		me->set_temp("charge/free", 1);		//����û�
		return 1;
	}

	//��ʦ���
	if(wizardp(me))
	{
		me->set_temp("charge/free", 1);		//����û�
		return 1;
	}
	
	//���IP
	if(g_Channel.filter_ip(me->querystr_temp("client/ip_address")))
	{
		me->set_temp("charge/free", 1);		//����û�
		return 1;
	}

	notify_fail("���ѹ��ڡ�");
	double value = Verify_Card(me->id(1), cardno, password, month);

	if(! value) return 0;
	
	me->set_temp("charge/login", current_time);		//��ʼ�Ʒ�ʱ��
	me->set_temp("charge/card", cardno);
	me->set_temp("charge/free", 0l);				//�շ��û�
	me->set_temp("charge/month", month);			//�Ƿ��¿�
	
	return value;
}

//�û�����ʱ����,����ʹ��ʱ��
void OnUserOut(CUser * me)
{
	if(me->query_temp("charge/free"))		//����û�
		return;

	LONG game_time = (current_time - me->query_temp("charge/login")) / 60;

	if(me->query_temp("charge/month"))		//�¿��û�
	{
		clear_online(me, me->querystr_temp("charge/card"), game_time);
		return;
	}

	if(game_time <= 0) return;

	double charge = game_time * g_game_count / 3.0;	//�۳�����

	charge = Charge_Card(me, me->querystr_temp("charge/card"), charge);
	if(! charge) return;
	
	//���
	me->set_temp("charge/login", current_time);

	//�ۼӵ�ͳ�Ʊ�
	double month_count, day_count, count;
	if(!Query_Game_Count_Table(day_count, month_count, count))
		return;
	
	day_count += charge;
	month_count += charge;
	count += charge;

	Modify_Game_Count_Table(day_count, month_count, count);
}

//-------------------------------------------------------------------------
//������а� ���ⲿ�������
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
			i, row[0], name[0] ? name : "������", fam[0] ? fam : "������", row[3]));
	}

	mysql_free_result(result);
	return 1;
}



