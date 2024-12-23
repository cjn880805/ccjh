#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>
#include "../../sql/sql.h"

extern MYSQL mysql;
extern MYSQL chargesql;		//�ƷѲ�ѯ

NPC_BEGIN(CNwiz_charge);

void create()
{
	set_name("�շѹ���Ա","charge");
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("grant", 99);
	set("no_kill",1);

	call_out(do_jiaoqian, 600);
};

static void do_jiaoqian(CContainer * ob, LONG param1, LONG param2)
{
	char msg[255];
	CChar * npc = (CChar *)ob;
	time_t current_time;
	time(&current_time);
	
	MAP2USER * user;
	iterator_user p;
	CUser * me;
	
	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		me = p->second;
		
		if( me->query_temp("net_dead")  ) //�����û�������
		{
			if (me->query_temp("����"))//����10��������
			{
				CContainer * obj = me->environment();
				if(!obj->query("wiz_room"))//����������˲���
				{
					tell_room(obj, snprintf(msg, 255, "%s����߶��뿪��Ϸ��", me->name()), me);
					g_Channel.do_channel(&g_Channel, 0, "sys", msg);
					me->command("quit");
				}
			}
			else
			{
				me->set_temp("����",1);
			}
			//DESTRUCT_OB(player, "cmd::quit");
			continue;
		}
		if (me->query_temp("����"))
		{
			me->delete_temp("����");
		}
		if(me->query_temp("charge/free"))		//����û�
			continue;
		
		if(me->query_temp("charge/month"))		//�¿��û�
			continue;
		
		LONG game_time = (current_time - me->query_temp("charge/login")) / 60;
		if(game_time <= 0) continue;
		
		double charge = game_time * 0.2 / 3.0;	//�۳�����

		charge =::Charge_Card(me, me->querystr_temp("charge/card"), charge);
		if(! charge) 
		{
			if(!me->query_temp("charge/over"))
			{
				tell_object(me, "$HIR���ĵ㿨���㣬������10�����ڱ�����Լ�����Ʒ�����ߣ������¸�����Ч�㿨��");
				me->set_temp("charge/over",1);
				me->set_temp("charge/login", current_time);
			}
			else
			{
				int DropAll(CChar *);
				CChar * player=me;
				DropAll(player);
				player->SaveToServer();
				me->Offline();
				tell_room(player->environment(), snprintf(msg, 255, "%s�뿪��Ϸ��", player->name()), player);
				
				g_Channel.do_channel(&g_Channel, 0, "sys", msg);
				DESTRUCT_OB(player, "cmd::quit");
			}
			continue;
		}
		
		//���
		me->set_temp("charge/login", current_time);
		
		//�ۼӵ�ͳ�Ʊ�
		double month_count, day_count, count;
		MYSQL_RES *result = NULL;
		int nResult = 0;
		
		//��鿨�ź������Ƿ���ȷ
		snprintf(msg, 255, "select day_count, month_count, count from Game_count where name = 'CCJH'");
		nResult = mysql_real_query(&chargesql, msg, strlen(msg));
		if( nResult != 0)
		{		
			output_error("Game_Count:%s!", mysql_error(&chargesql));
			continue ;
		}
		
		result = mysql_store_result(&chargesql);
		if(result == NULL)
		{		
			output_error("Game_Count:  store null");
			continue ;
		}
		
		int n = mysql_num_rows(result);
		if(n == 0)
		{
			mysql_free_result(result);
			continue ;		
		}
		
		MYSQL_ROW row;
		row = mysql_fetch_row(result);
		if(row == NULL)
		{
			mysql_free_result(result);
			continue ;
		}
		
		day_count = atof(row[0]);
		month_count = atof(row[1]);
		count = atof(row[2]);
		
		mysql_free_result(result);

		//�޸�Game_count��
		day_count += charge;
		month_count += charge;
		count += charge;
		
		sprintf(msg, "update Game_count set day_count = %.1f, month_count = %.1f, count = %.1f where name = 'CCJH'", day_count, month_count, count);
		nResult = mysql_real_query(&chargesql, msg, strlen(msg));
		if( nResult != 0)
		{
			output_error("Modify_Game_count_Table:%s!", mysql_error(&chargesql));
			continue ;
		}
    }
	npc->call_out(do_jiaoqian, 600);
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
	if(left < 0.1) 	left = 0;
	
	sprintf(msg, "update Card set value = %.1f where cardno = '%s'", left, cardno);
	
	nResult = mysql_real_query(&chargesql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("Charge_Card:%s!", mysql_error(&chargesql));
		return 0;
	}

	sprintf(msg, "�û�%s(%s)��(%s)�Ʒ�%.1f��.���%.1f.", me->name(1), me->id(1), cardno, resume, left);
	output_error(msg);
	if(!left)
		return 0;
	else
		return resume;
}


NPC_END;
