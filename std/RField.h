#include "../server/Room.h"
#include "../server/Npc.h"

#define FIELD_BEGIN(room_name)	class room_name : public CRField	{	public:	room_name(){};	virtual ~room_name(){};
#define FIELD_END		};	

//��׼Ұ�ⳡ��
//���Զ������������
//Lanwood 2001-02-03

ROOM_BEGIN(CRField);

//����ɫ����ʱִ��
//�� set("monster_chance", 60) ���ù�����ּ��ʡ�0~100
virtual void init(CChar *me)
{
	int chance = query("monster_chance");

	if(! chance) chance = 50;
	if(userp(me) && random(100) < chance)
	{
		remove_call_out(present_monster);
		call_out(present_monster, 1, me->object_id());
	}
}

static void present_monster(CContainer * ob, LONG param1, LONG param2)
{
	char msg[20];
	CChar * me = (CChar *)ob->Present(param1);
	if(! me) return;

	const char * mon = "monster_1";
	
	if(ob->query("monster_type") == 2 && ! random(3))
		mon = "monster_2";
	
	CNpc * monster = load_npc(mon);

	//�жϸù���ȼ���
	if(monster->query("monster_lvl") < me->query_temp("apply/protect"))
	{
		DESTRUCT_OB(monster, "CRfield::present_monster");
		return;
	}

	monster->move(ob);

	mon = monster->querystr("present_msg");
	if(! mon[0])
		mon = "�������ܣ����Ӳݴ��дڳ�һ��$n������$N��ǰ��";

	message_vision(mon, me, monster);
	monster->command(snprintf(msg, 20, "kill %ld", param1));
}
	
ROOM_END;