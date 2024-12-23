#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

extern MYSQL mysql;

NPC_BEGIN(CNcorps_kill);

void create()
{
	set_name("Ãð°ïÊ¹Õß","kill corps");
	set("gender", "ÄÐÐÔ");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);
	set("grant", 99);
	set("no_kill",1);

	set_inquiry("°ïÅÉ¾ö¶·", ask_juedou);

};

static char * ask_juedou(CNpc * npc, CChar * me)
{
	if(me->querymap("corps"))
	{
		char msg[255];
		int nResult = 0;
		
		snprintf(msg, 255, "delete from t_room where obj_id = '%s'",me->querystr("corps/id"));
		nResult = mysql_real_query(&mysql, msg, strlen(msg));
		if( nResult != 0)
		{		
			message_vision(	snprintf(msg, 255, "É¾³ý°ï»á$HIR %s &COMÊ§°Ü¡£", load_room(me->querystr("corps/id"))->name()),me);
		}
		else
		{
			message_vision(snprintf(msg, 255, "É¾³ý°ï»á$HIR %s &COM³É¹¦¡£", load_room(me->querystr("corps/id"))->name()),me);
			me->del("corps");
		}
	}
	return 0;
}

NPC_END;