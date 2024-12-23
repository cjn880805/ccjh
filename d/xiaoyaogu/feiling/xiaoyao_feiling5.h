//xiaoyao_feiling5.h 飞凌之心
//秦波 2003、3、15

XiaoYao_BEGIN(CRXiaoYao_feiling5);

virtual void create()
{
	set_name( "飞凌之心");
	set("no_autosave",1);
	set("index",5);

	add_item("shicheng");
	add_door("飞凌之左臂室", "逍遥谷飞凌之左臂室", "逍遥谷飞凌之心");
	add_door("飞凌之右臂室", "逍遥谷飞凌之右臂室", "逍遥谷飞凌之心");
	add_door("飞凌之帽", "逍遥谷飞凌之帽", "逍遥谷飞凌之心");
	add_door("飞凌之履", "逍遥谷飞凌之履", "逍遥谷飞凌之心");

};

XiaoYao_END;
